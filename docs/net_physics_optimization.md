# GPNet `net.py` 物理优化流程笔记

本文对应 `GPNet.forward_frame` 中 **`# physics optimization`** 段（约 228–353 行）及前置输入，便于与 Unity `CarticulateGpNetPySolver` 对照。

---

## 1. 前置：进入物理块之前（非优化本体）

来自 PL / IK / VR 子网与 SMPL 运动学，本帧在 `# physics optimization` 之前已具备：

| 中间量 | 含义 |
|--------|------|
| `pose` | 24 关节旋转矩阵（目标姿态，来自 IK） |
| `cjoint` | 5 个接触身体索引 `j_contact` 上的**模板**世界坐标（由 `pRJ`、`pose[0]` 得到，尚未加根平移预测） |
| `stationary_prob` | VR 网输出的 5 维静止概率 |
| `velocity` | 由 `last_cjoint`、`cjoint`、`stationary_weight`、`vWR` 等融合得到的**世界系线速度**（用于预测接触轨迹） |
| `stationary_weight` | `(stationary_prob * 5 - 3).clip(0, 1)` |
| `last_cjoint` | 上一帧结束时的接触模板位置（本帧在 VR 段已更新） |

**类成员/常量**：`self.physics_model`（`carticulate` 动力学）、`self.contact`（上一帧接触掩码）、`self.floor_y`、`dt`、`kp_pose`、`kd_pose`、`kp_tran`、`kd_tran`、`alpha_pd`、`beta_*`、`j_contact` 等。

**动力学库**（`carticulate.DynamicModel`）：由 `cart.get_dynamic_model('models/SMPL_male.pkl')` 建立；内部为 SMPL 骨长 + 惯量 + 重力。

---

## 2. 分支 A：首帧初始化 `not self.is_init`

| 输入 | 输出 / 副作用 |
|------|----------------|
| `pose.numpy()` | |
| `floor_y - cjoint[:, 1].min()`（脚底最低高度） | 根平移 `tran = [0, floor_y - min_y, 0]` |
| — | `set_state_R(pose, tran, qdot_zeros(75))` |
| — | `is_init = True` |

本帧**不执行**两次 LSQR、QP、接触细化；末尾仍通过 `get_state_R()` 得到 `refined_pose`、`refined_tran` 用于返回。

---

## 3. 分支 B：后续帧 — 逐步输入输出

### 3.1 从物理模型读取当前量

| 输入 | 输出 |
|------|------|
| — | `pose_cur, tran_cur, qdot ← get_state_R()` |
| `j_contact`（5 个关节索引） | `cjoint_cur`，`cvel_cur`（各 `get_position` / `get_linear_velocity` 堆叠） |
| 同上 | `cJ_cur`（15×75），`cJdot_cur`（15×75） |
| — | `M ← mass_matrix()`（75×75），`h ← inverse_dynamics(0)`（75） |
| `stationary_prob` | `stationary = prob > 0.7`（bool×5） |

含义：`pose_cur/tran_cur/qdot` 为**上一帧** `update_state` 后的状态；\(M,h,J\) 均在该状态下计算。

### 3.2 双路 RSPD（姿态 + 平移目标）

**姿态支路**

- 构造小旋转 `R = axis_angle(qdot[3:] * alpha_pd * dt)`。
- `delta_pose`：由 `pose_cur`、`R`、`pose` 算相对轴角误差（融合 \(\alpha_{pd}\) 时与稳定 PD 一致）。
- `thetaddotdes`（72 维）：
  \[
  \ddot\theta_{\mathrm{des}} =
  \frac{k_p \Delta_{\mathrm{pose}} - k_d \dot q_{3:}}{1 + k_d \alpha_{pd} \Delta t}
  \]

**平移 / 接触目标支路**

- 将模板 `cjoint` 与 `tran_cur`、`velocity`、`dt` 合成世界系预测，再与 `cjoint_cur` 按 `stationary_weight` **lerp**（静止脚更贴仿真接触点）。
- `delta_tran`、`rddotdes`（15 维展平）：对接触点线加速度的 PD 目标，形式与姿态分支对称（含 `alpha_pd` 分母）。

| 输入 | 输出 |
|------|------|
| `pose_cur`, `pose`, `qdot[3:]` | `thetaddotdes` |
| `tran_cur`, `velocity`, `cjoint`（numpy）, `cjoint_cur`, `cvel_cur`, `stationary_weight` | 更新后的 `cjoint`（5×3）, `rddotdes` |

### 3.3 第一次 LSQR（无接触力项）

**脚趾偏移**：`cjoint_cur[0, 1] -= 0.15`，`cjoint[0, 1] -= 0.15`（根接触竖直参考对齐，与 Unity `toeYOffset` 类同）。

**权重** `k`：`beta_cjoint` 初值，对已判定 `self.contact` 的索引再 `×10`。

**最小二乘**（概念）：

- 块1：\([\ 0_{72\times3}\ |\ I_{72}\ ]\ddot q \approx \ddot\theta_{\mathrm{des}}\)
- 块2：\(\sqrt{k}\, J_c \ddot q \approx \sqrt{k}\,(\ddot r_{\mathrm{des}} - \dot J_c \dot q)\)
- 块3：\(\sqrt{\beta_\tau}\, M\ddot q \approx -\sqrt{\beta_\tau}\, h\)（软正则，**不含** \(J^\top f\)）

| 输入 | 输出 |
|------|------|
| `thetaddotdes`, `cJ_cur`, `cJdot_cur`, `qdot`, `rddotdes`, `M`, `h`, `k` | `qddot`（75） |
| `M[:6]`, `h[:6]`, `qddot` | `residual_force`：浮动基前 6 维 \((M\ddot q + h)_{1:6}\)，供 QP 用接触力解释 |

### 3.4 接触掩码与潜在接触

| 输入 | 输出 |
|------|------|
| `stationary`, `self.contact`, `cjoint_cur` 与 `floor_y`，脚间高度差 `vdist` | `contact`（5）, `potential_contact`（5） |
| `get_position` 髋–膝矢量 | 若两腿接近竖直（\(<\pi/4\)），可关 `contact[0]`、`potential_contact[0]` |

### 3.5 `_explain_residual_force`（摩擦锥 QP）

对 `contact` 为真的点堆叠子雅可比 \(J\)（映射到基座 6 维），在摩擦锥（或手部抓取：无界）下解二次规划，使 \(J^\top B f\) 逼近 `residual_force`（实现中为 `JTB @ force`，见第 7 节）。

| 输入 | 输出 |
|------|------|
| `contact`, `cJ_cur`, `cjoint_cur`, `residual_force`, `mu`→`B`, `beta_extforce` | `force`, `err`, `forceB` |

若 `err > 400` 且存在 `potential_contact`，按 `cjoint_cur` 高度从低到高尝试锁定为接触，需 `contact_counter` 连续多帧（默认 5）且误差比改善才接受。

### 3.6 接触目标高度修正（贴地）

| 输入 | 输出 |
|------|------|
| `contact` ∧ `near_ground`（\(y < floor_y + 0.15\)） | `cjoint` 的 \(y\) 向 `floor_y` lerp |
| `cjoint[:,1] < floor_y` | clamp 到 `floor_y` |

随后**重算** `delta_tran`、`rddotdes`（与 3.2 公式相同，用于第二次 LSQR）。

### 3.7 第二次 LSQR + `update_state`

- 若有接触：`J = cJ_cur[contact]` 展平，`torque = J.T @ (B @ force)`；无接触：`torque = 0`。
- `A` 与第一次类似，但第三块系数为 `sqrt(beta_torque * 3) * M`，`b` 的第三段为 `sqrt(...) * (-h + torque)`。

| 输入 | 输出 |
|------|------|
| `thetaddotdes`, 新 `rddotdes`, `M`, `h`, `cJ_cur`, `cJdot_cur`, `qdot`, `torque` | `qddot`（75） |
| `qddot`, `dt` | `update_state` → 更新 `physics_model` 内状态 |
| `contact` | `self.contact ← contact`（供下一帧 `k` 加权） |

### 3.8 可视化（可选）

不改变数值状态；按需画接触力、残差、阻挡块等。

---

## 4. 物理块结束（两分支共通）

| 输入 | 输出 |
|------|------|
| `get_state_R()` | `refined_pose`, `refined_tran`, `qdot` |

`forward_frame` **返回** `refined_pose`, `refined_tran`（tensor）。

---

## 5. 与 Unity 的对应（便于跳转）

| Python | Unity（约） |
|--------|-------------|
| RSPD + `cjoint` 预测 | `CarticulateGpNetPySolver.PdTracking.cs` |
| LSQR 装配 | `CarticulateGpNetPySolver.LsqrAssembly.cs` |
| 摩擦锥 QP | `CarticulateGpNetPySolver.ContactQp.cs` |
| 超参数 | `GlobalPosePhysicsSettings.asset` / `GlobalPosePhysicsSettings.cs` |
| 驱动入口 | `CarticulateDynamicsDriver.cs`（`StartGlobalPosePhysics`） |

---

## 6. 流程简图（后续帧）

```
网络 pose / cjoint 模板 / velocity / stationary
        │
        ▼
physics_model: get_state_R, M, h, J, J̇, 接触运动学
        │
        ▼
双路 RSPD → thetaddotdes, rddotdes, 更新 cjoint
        │
        ▼
LSQR #1（无 Jᵀf）→ qddot → residual_force (基座6维)
        │
        ▼
接触判定 + potential_contact
        │
        ▼
QP 解释 residual_force → force, torque
        │
        ▼
修正 cjoint 高度（贴地）→ 更新 rddotdes
        │
        ▼
LSQR #2（b 含 -h + torque）→ qddot → update_state
        │
        ▼
get_state_R → refined_pose, refined_tran
```

---

## 7. 数据结构与张量维度（`net.py`）

以下若无说明，均为**单帧**；`N_c = 5` 为固定接触身体数 `len(j_contact)`。

### 7.1 广义坐标与动力学（`physics_model`）

| 符号 / 变量 | 形状 | 说明 |
|-------------|------|------|
| `qdot` | `(75,)` | 广义速度；**前 3** 为根线速度；`qdot[3:]` 为 **72** 维角向部分 |
| `qddot` | `(75,)` | 广义加速度（LSQR 解） |
| `pose` / `pose_cur` | `(24, 3, 3)` | 各关节相对旋转矩阵 |
| `tran_cur` | `(3,)` | 根平移（世界系） |
| `M` | `(75, 75)` | 质量矩阵 `mass_matrix()` |
| `h` | `(75,)` | 偏置力，`inverse_dynamics(np.zeros(75))` |

**约定**：`thetaddotdes` 与 `[0_{72×3} | I_{72}]` 只对 **后 72 维** \(\ddot q\) 显式跟踪；前 3 维通过 \(J_c\)、\(M\) 耦合。

### 7.2 接触点与运动学雅可比（5 个 `j_contact`）

| 变量 | 形状 | 说明 |
|------|------|------|
| `j_contact` | 5 个 int | `(0, 10, 11, 22, 23)` |
| `cjoint_cur` | `(5, 3)` | 当前仿真下各接触点世界位置 |
| `cvel_cur` | `(5, 3)` | 各点世界线速度 |
| `cjoint`（预测/目标） | `(5, 3)` | PD 与贴地修正后的目标接触位置 |
| `cJ_cur` | `(15, 75)` | 5 块 `get_linear_Jacobian(j)`，每块 `(3, 75)` 竖拼 |
| `cJdot_cur` | `(15, 75)` | 同上，`get_linear_Jacobian_dot` |
| `rddotdes` | `(15,)` | 5×3 线加速度目标，顺序与 `cJ_cur` 行一致 |

**reshape**：`cJ_cur.reshape(5, 3, 75)` 时，单点 `cJ_cur[i]` 为 `(3, 75)`。

### 7.3 网络与 RSPD 相关

| 变量 | 形状 | 说明 |
|------|------|------|
| `stationary_prob` | `(5,)` | VR 输出经 sigmoid |
| `stationary` | `(5,)` bool | `prob > 0.7` |
| `stationary_weight` | `(5,)` | 用于与 `cjoint_cur` 的 lerp |
| `delta_pose`（内部） | 展平 `(72,)` | 与 `thetaddotdes`、`qdot[3:]` 对齐 |
| `thetaddotdes` | `(72,)` | 姿态 PD 输出 |
| `R`（稳定 PD） | `(24, 3, 3)` | 由 `qdot[3:]` 构造轴角旋转 |

### 7.4 第一次 / 第二次 LSQR 堆叠

标量权重 `k.reshape(15, 1)` 与 `cJ_cur` 的 15 行逐行相乘。

| 块 | `A` 形状 | `b` 形状 |
|----|-----------|----------|
| 关节跟踪 | `(72, 75)` `hstack(0, I)` | `(72,)` `thetaddotdes` |
| 接触加速度 | `(15, 75)` `sqrt(k)*cJ_cur` | `(15,)` `sqrt(k)*(-cJdot_cur@qdot + rddotdes)` |
| 动力学正则 | `(75, 75)` `sqrt(β)·M` 或 `sqrt(3β)·M` | `(75,)` `sqrt(β)·(-h)` 或 `sqrt(3β)·(-h+torque)` |

- **合计** `A`：**`(162, 75)`**，`b`：**`(162,)`**。
- 未知数：**`\ddot q` → `(75,)`**。

### 7.5 浮动基残差与 QP

| 变量 | 形状 | 说明 |
|------|------|------|
| `residual_force` | `(6,)` | `M[:6,:] @ qddot + h[:6]`，浮动基子空间 |

**`_explain_residual_force`（有接触时）**

- `J = contact_Jacobian.reshape(5,3,75)[contact,:,:6].reshape(-1,6)` → **`(3·N_act, 6)`**。
- **地面**：`self.B` **`(3, 4)`**（锥系数→3D 力）；对应 `lb` 片段长度 **4**，非负。
- **手抓取**：`I_3`，`lb` 为 **`(-∞)^3`**，变量维 **3**。
- `m = 4·(地面接触数) + 3·(手抓取数)`（激活接触）。
- `JTB = J.T @ block_diagonal(B)` → **`(6, m)`**；`force`（OSQP）→ **`(m,)`**；`error = ‖JTB @ force - residual_force‖`。

**第二步广义力**

- `J_full = cJ_cur.reshape(5,3,75)[contact].reshape(-1,75)` → **`(3·N_act, 75)`**。
- `force_phys = B_blk @ force` → **`(3·N_act,)`**；**`torque = J_full.T @ force_phys`** → **`(75,)`**。

### 7.6 接触掩码与其它

| 变量 | 形状 |
|------|------|
| `contact` / `potential_contact` | `(5,)` bool |
| `self.contact` | `(5,)` bool |
| `contact_counter` | `(5,)` int |
| `k` | `(5, 3)`，展平 `(15,)` 参与 `sqrt(k)` |

### 7.7 摩擦矩阵 `B`（地面，初始化）

`net.py` 中 `self.B`：**`(3, 4)`**，归一化后与 `mu` 构成摩擦锥基；具体分量顺序以 108–110 行实现为准。

---

*文档依据：`GlobalPose/net.py`（`forward_frame`、`_explain_residual_force`）、`carticulate/utils.py`（`get_dynamic_model`）。`residual_force` 的 6 维分量顺序与 `carticulate` 浮动基定义一致。*
