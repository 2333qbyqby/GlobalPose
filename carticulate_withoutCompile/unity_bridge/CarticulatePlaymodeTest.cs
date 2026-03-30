using System;
using System.IO;
using System.Runtime.InteropServices;
using UnityEngine;

namespace Carticulate
{
    /// <summary>
    /// 挂在任意 GameObject 上，进入 Play 后自动跑一组原生 API 自检。
    /// 请把 dynamic 的 .armature 放到 StreamingAssets（或改 <see cref="UseAbsolutePath"/>）。
    /// </summary>
    public sealed class CarticulatePlaymodeTest : MonoBehaviour
    {
        [Tooltip("相对 StreamingAssets 的 dynamic armature 文件名，例如 SMPL_male.armature")]
        [SerializeField] string dynamicArmatureRelativePath = "TestArmature/SMPL_male.armature";

        [Tooltip("勾选后使用下面绝对路径，忽略 StreamingAssets")]
        [SerializeField] bool useAbsolutePath;

        [SerializeField] string absoluteArmaturePath = "";

        [Tooltip("顺带测试 Kinematic（需 kinematic 用的 .armature；留空则跳过）")]
        [SerializeField] string kinematicArmatureRelativePath = "";

        [SerializeField] bool runOnStart = true;

        void Start()
        {
            if (!runOnStart)
                return;
            RunAll();
        }

        [ContextMenu("Run Carticulate Native Tests")]
        public void RunAll()
        {
            try
            {
                TestVersion();
                var path = ResolveArmaturePath();
                if (string.IsNullOrEmpty(path) || !File.Exists(path))
                {
                    Debug.LogError($"[Carticulate] 找不到 armature 文件: {path}\n" +
                                   "请将 dynamic .armature 复制到 Assets/StreamingAssets 下对应子目录，或改用绝对路径。");
                    return;
                }
                TestDynamic(path);
                if (!string.IsNullOrWhiteSpace(kinematicArmatureRelativePath))
                {
                    var kpath = Path.Combine(Application.streamingAssetsPath, kinematicArmatureRelativePath);
                    if (File.Exists(kpath))
                        TestKinematic(kpath);
                    else
                        Debug.LogWarning($"[Carticulate] 跳过 Kinematic：未找到 {kpath}");
                }
            }
            catch (DllNotFoundException e)
            {
                Debug.LogError("[Carticulate] 未加载 carticulate_unity.dll。是否已放到 Assets/Plugins/x86_64/ ？\n" + e);
            }
            catch (Exception e)
            {
                Debug.LogException(e);
            }
        }

        string ResolveArmaturePath()
        {
            if (useAbsolutePath && !string.IsNullOrWhiteSpace(absoluteArmaturePath))
                return absoluteArmaturePath.Trim();
            return Path.Combine(Application.streamingAssetsPath, dynamicArmatureRelativePath);
        }

        static void TestVersion()
        {
            var p = Native.CU_Version();
            if (p == IntPtr.Zero)
            {
                Debug.Log("[Carticulate] CU_Version null");
                return;
            }
            var s = Marshal.PtrToStringAnsi(p);
            Debug.Log($"[Carticulate] {s}");
        }

        static void AssertOk(int code, string step)
        {
            if (code != Native.Ok)
                throw new InvalidOperationException($"[Carticulate] {step} 返回 {code} (期望 {Native.Ok})");
        }

        void TestDynamic(string armaturePath)
        {
            Debug.Log($"[Carticulate] Dynamic 加载: {armaturePath}");
            int err = Native.CU_Dynamic_Create(armaturePath, out var handle);
            AssertOk(err, "CU_Dynamic_Create");
            try
            {
                err = Native.CU_Dynamic_GetNJoints(handle, out int nj);
                AssertOk(err, "CU_Dynamic_GetNJoints");
                err = Native.CU_Dynamic_GetVelDim(handle, out int vd);
                AssertOk(err, "CU_Dynamic_GetVelDim");
                Debug.Log($"[Carticulate] Dynamic n_joints={nj}, vel_dim={vd} (期望 {3 + 3 * nj})");

                var quat = new float[nj * 4];
                for (int i = 0; i < nj; i++)
                {
                    quat[i * 4 + 0] = 1f;
                    quat[i * 4 + 1] = 0f;
                    quat[i * 4 + 2] = 0f;
                    quat[i * 4 + 3] = 0f;
                }
                var root = new float[3];
                var vel = new float[vd];
                err = Native.CU_Dynamic_SetStateQ(handle, quat, nj, root, vel, vel.Length);
                AssertOk(err, "CU_Dynamic_SetStateQ");

                var quat2 = new float[nj * 4];
                var root2 = new float[3];
                var vel2 = new float[vd];
                err = Native.CU_Dynamic_GetStateQ(handle, quat2, nj, root2, vel2, vel2.Length);
                AssertOk(err, "CU_Dynamic_GetStateQ");
                Debug.Log($"[Carticulate] 根位移读回: ({root2[0]:F4},{root2[1]:F4},{root2[2]:F4})");

                var force = new float[vd];
                var acc = new float[vd];
                err = Native.CU_Dynamic_ForwardDynamics(handle, force, force.Length, acc, acc.Length);
                AssertOk(err, "CU_Dynamic_ForwardDynamics");
                Debug.Log($"[Carticulate] ForwardDynamics 零力矩 |acc_0| = {Mathf.Abs(acc[0]):E3}");

                float dt = Time.fixedDeltaTime > 0f ? Time.fixedDeltaTime : 1f / 60f;
                err = Native.CU_Dynamic_UpdateState(handle, acc, acc.Length, dt);
                AssertOk(err, "CU_Dynamic_UpdateState");

                var local0 = new float[3];
                var world = new float[3];
                err = Native.CU_Dynamic_GetJointWorldPosition(handle, 0, local0, world);
                AssertOk(err, "CU_Dynamic_GetJointWorldPosition");
                var wq = new float[4];
                err = Native.CU_Dynamic_GetJointWorldQuat(handle, 0, wq);
                AssertOk(err, "CU_Dynamic_GetJointWorldQuat");
                Debug.Log($"[Carticulate] joint0 world pos ({world[0]:F4},{world[1]:F4},{world[2]:F4}), quat wxyz ({wq[0]:F4},{wq[1]:F4},{wq[2]:F4},{wq[3]:F4})");

                Debug.Log("[Carticulate] Dynamic 测试通过。");
            }
            finally
            {
                Native.CU_Dynamic_Destroy(handle);
            }
        }

        static void TestKinematic(string armaturePath)
        {
            Debug.Log($"[Carticulate] Kinematic 加载: {armaturePath}");
            int err = Native.CU_Kinematic_Create(armaturePath, out var handle);
            if (err != Native.Ok)
            {
                Debug.LogWarning($"[Carticulate] Kinematic 创建失败 code={err}（可能不是 kinematic 格式 armature）");
                return;
            }
            try
            {
                err = Native.CU_Kinematic_GetNJoints(handle, out int nj);
                AssertOk(err, "CU_Kinematic_GetNJoints");
                err = Native.CU_Kinematic_GetDeltaDim(handle, out int dd);
                AssertOk(err, "CU_Kinematic_GetDeltaDim");

                var quat = new float[nj * 4];
                for (int i = 0; i < nj; i++)
                {
                    quat[i * 4] = 1f;
                }
                var root = new float[3];
                err = Native.CU_Kinematic_SetStateQ(handle, quat, nj, root);
                AssertOk(err, "CU_Kinematic_SetStateQ");

                var delta = new float[dd];
                err = Native.CU_Kinematic_UpdateState(handle, delta, delta.Length);
                AssertOk(err, "CU_Kinematic_UpdateState");

                Debug.Log($"[Carticulate] Kinematic 测试通过 (n={nj}, delta_dim={dd})。");
            }
            finally
            {
                Native.CU_Kinematic_Destroy(handle);
            }
        }
    }
}
