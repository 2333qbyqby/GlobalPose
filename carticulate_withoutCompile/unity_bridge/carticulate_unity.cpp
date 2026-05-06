#include "carticulate_unity_api.h"

#include "../dynamics/dynamic_model.h"
#include "../kinematics/kinematic_model.h"

#include <Eigen/Dense>

#include <cstdint>
#include <cstring>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

namespace {

std::mutex g_mu;
int64_t g_next_id = 1;
std::unordered_map<int64_t, std::unique_ptr<DynamicModel>> g_dyn;
std::unordered_map<int64_t, std::unique_ptr<KinematicModel>> g_kin;

inline bool copy_quats_in(std::vector<Eigen::Quaternionf> &pose,
                          const float *wxyz,
                          int n_floats,
                          int n_joints)
{
    if (!wxyz || n_floats != n_joints * 4)
        return false;
    pose.resize(n_joints);
    for (int i = 0; i < n_joints; i++) {
        pose[i] = Eigen::Quaternionf(
            wxyz[i * 4 + 0],
            wxyz[i * 4 + 1],
            wxyz[i * 4 + 2],
            wxyz[i * 4 + 3]);
    }
    return true;
}

inline void copy_quats_out(const std::vector<Eigen::Quaternionf> &pose, float *wxyz, int n_floats)
{
    const int n = static_cast<int>(pose.size());
    for (int i = 0; i < n; i++) {
        wxyz[i * 4 + 0] = pose[i].w();
        wxyz[i * 4 + 1] = pose[i].x();
        wxyz[i * 4 + 2] = pose[i].y();
        wxyz[i * 4 + 3] = pose[i].z();
    }
    (void)n_floats;
}

} // namespace

extern "C" {

CU_API const char *CU_Version(void)
{
    return "carticulate_unity 0.1";
}

static int vel_dim(const DynamicModel &m)
{
    return m.get_armature().n_joints * 3 + 3;
}

/* ---------- Dynamic ---------- */

CU_API int CU_Dynamic_Create(const char *armature_path_utf8, int64_t *out_handle)
{
    if (!out_handle || !armature_path_utf8 || armature_path_utf8[0] == '\0')
        return CU_ERR_INVALID_ARG;
    try {
        auto model = std::make_unique<DynamicModel>(std::string(armature_path_utf8));
        std::lock_guard<std::mutex> lock(g_mu);
        const int64_t id = g_next_id++;
        g_dyn[id] = std::move(model);
        *out_handle = id;
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API void CU_Dynamic_Destroy(int64_t handle)
{
    std::lock_guard<std::mutex> lock(g_mu);
    g_dyn.erase(handle);
}

CU_API int CU_Dynamic_GetNJoints(int64_t handle, int *out_n)
{
    if (!out_n)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_dyn.find(handle);
    if (it == g_dyn.end())
        return CU_ERR_BAD_HANDLE;
    *out_n = it->second->get_armature().n_joints;
    return CU_OK;
}

CU_API int CU_Dynamic_GetVelDim(int64_t handle, int *out_dim)
{
    if (!out_dim)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_dyn.find(handle);
    if (it == g_dyn.end())
        return CU_ERR_BAD_HANDLE;
    *out_dim = vel_dim(*it->second);
    return CU_OK;
}

CU_API int CU_Dynamic_SetStateQ(int64_t handle,
                                const float *joint_quat_wxyz,
                                int joint_count,
                                const float root_translation_xyz[3],
                                const float *vel,
                                int vel_len)
{
    if (!joint_quat_wxyz || !root_translation_xyz || !vel)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_dyn.find(handle);
    if (it == g_dyn.end())
        return CU_ERR_BAD_HANDLE;
    try {
        DynamicModel &m = *it->second;
        const int nj = m.get_armature().n_joints;
        if (joint_count != nj)
            return CU_ERR_INVALID_ARG;
        std::vector<Eigen::Quaternionf> pose;
        if (!copy_quats_in(pose, joint_quat_wxyz, joint_count * 4, nj))
            return CU_ERR_INVALID_ARG;
        const int vd = vel_dim(m);
        if (vel_len != vd)
            return CU_ERR_INVALID_ARG;
        Eigen::Map<const Eigen::VectorXf> v(vel, vd);
        Eigen::Vector3f tran(root_translation_xyz[0], root_translation_xyz[1], root_translation_xyz[2]);
        m.set_state_q(pose, tran, v);
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API int CU_Dynamic_GetStateQ(int64_t handle,
                               float *joint_quat_wxyz,
                               int joint_count,
                               float root_translation_xyz[3],
                               float *vel,
                               int vel_len)
{
    if (!joint_quat_wxyz || !root_translation_xyz || !vel)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_dyn.find(handle);
    if (it == g_dyn.end())
        return CU_ERR_BAD_HANDLE;
    try {
        DynamicModel &m = *it->second;
        const int nj = m.get_armature().n_joints;
        if (joint_count != nj)
            return CU_ERR_INVALID_ARG;
        const int vd = vel_dim(m);
        if (vel_len != vd)
            return CU_ERR_INVALID_ARG;
        std::vector<Eigen::Quaternionf> pose;
        Eigen::Vector3f tran;
        Eigen::VectorXf vvec(vd);
        m.get_state_q(pose, tran, vvec);
        copy_quats_out(pose, joint_quat_wxyz, nj * 4);
        root_translation_xyz[0] = tran.x();
        root_translation_xyz[1] = tran.y();
        root_translation_xyz[2] = tran.z();
        Eigen::Map<Eigen::VectorXf>(vel, vd) = vvec;
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API int CU_Dynamic_UpdateState(int64_t handle, const float *acc, int acc_len, float delta_t)
{
    if (!acc)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_dyn.find(handle);
    if (it == g_dyn.end())
        return CU_ERR_BAD_HANDLE;
    try {
        DynamicModel &m = *it->second;
        const int ad = vel_dim(m);
        if (acc_len != ad)
            return CU_ERR_INVALID_ARG;
        Eigen::Map<const Eigen::VectorXf> a(acc, ad);
        m.update_state(a, delta_t);
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API int CU_Dynamic_ForwardDynamics(int64_t handle,
                                       const float *force,
                                       int force_len,
                                       float *out_acc,
                                       int acc_len)
{
    if (!force || !out_acc)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_dyn.find(handle);
    if (it == g_dyn.end())
        return CU_ERR_BAD_HANDLE;
    try {
        DynamicModel &m = *it->second;
        const int d = vel_dim(m);
        if (force_len != d || acc_len != d)
            return CU_ERR_INVALID_ARG;
        Eigen::Map<const Eigen::VectorXf> f(force, d);
        Eigen::VectorXf a = m.forward_dynamics(f);
        Eigen::Map<Eigen::VectorXf>(out_acc, d) = a;
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API int CU_Dynamic_GetJointWorldPosition(int64_t handle,
                                             int joint_idx,
                                             const float local_xyz[3],
                                             float out_world_xyz[3])
{
    if (!local_xyz || !out_world_xyz)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_dyn.find(handle);
    if (it == g_dyn.end())
        return CU_ERR_BAD_HANDLE;
    try {
        DynamicModel &m = *it->second;
        if (joint_idx < 0 || joint_idx >= m.get_armature().n_joints)
            return CU_ERR_INVALID_ARG;
        Eigen::Vector3f local(local_xyz[0], local_xyz[1], local_xyz[2]);
        Eigen::Vector3f w = m.get_position(joint_idx, local);
        out_world_xyz[0] = w.x();
        out_world_xyz[1] = w.y();
        out_world_xyz[2] = w.z();
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API int CU_Dynamic_GetJointWorldQuat(int64_t handle,
                                        int joint_idx,
                                        float out_wxyz[4])
{
    if (!out_wxyz)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_dyn.find(handle);
    if (it == g_dyn.end())
        return CU_ERR_BAD_HANDLE;
    try {
        DynamicModel &m = *it->second;
        if (joint_idx < 0 || joint_idx >= m.get_armature().n_joints)
            return CU_ERR_INVALID_ARG;
        Eigen::Quaternionf q = m.get_orientation_q(joint_idx);
        out_wxyz[0] = q.w();
        out_wxyz[1] = q.x();
        out_wxyz[2] = q.y();
        out_wxyz[3] = q.z();
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API int CU_Dynamic_GetMassMatrix(int64_t handle,
                                    float *out_mass_row_major,
                                    int out_len)
{
    if (!out_mass_row_major)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_dyn.find(handle);
    if (it == g_dyn.end())
        return CU_ERR_BAD_HANDLE;
    try {
        DynamicModel &m = *it->second;
        const int d = vel_dim(m);
        if (out_len != d * d)
            return CU_ERR_INVALID_ARG;
        Eigen::MatrixXf M = m.mass_matrix();
        if (M.rows() != d || M.cols() != d)
            return CU_ERR_EXCEPTION;
        for (int r = 0; r < d; r++) {
            for (int c = 0; c < d; c++) {
                out_mass_row_major[r * d + c] = M(r, c);
            }
        }
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API int CU_Dynamic_GetBiasForce(int64_t handle,
                                   float *out_h,
                                   int out_len)
{
    if (!out_h)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_dyn.find(handle);
    if (it == g_dyn.end())
        return CU_ERR_BAD_HANDLE;
    try {
        DynamicModel &m = *it->second;
        const int d = vel_dim(m);
        if (out_len != d)
            return CU_ERR_INVALID_ARG;
        Eigen::VectorXf zero = Eigen::VectorXf::Zero(d);
        Eigen::VectorXf h = m.inverse_dynamics(zero);
        if (h.size() != d)
            return CU_ERR_EXCEPTION;
        Eigen::Map<Eigen::VectorXf>(out_h, d) = h;
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API int CU_Dynamic_InverseDynamics(int64_t handle,
                                      const float *acc,
                                      int acc_len,
                                      float *out_force,
                                      int out_len)
{
    if (!acc || !out_force)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_dyn.find(handle);
    if (it == g_dyn.end())
        return CU_ERR_BAD_HANDLE;
    try {
        DynamicModel &m = *it->second;
        const int d = vel_dim(m);
        if (acc_len != d || out_len != d)
            return CU_ERR_INVALID_ARG;
        Eigen::Map<const Eigen::VectorXf> a(acc, d);
        Eigen::VectorXf f = m.inverse_dynamics(a);
        if (f.size() != d)
            return CU_ERR_EXCEPTION;
        Eigen::Map<Eigen::VectorXf>(out_force, d) = f;
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API int CU_Dynamic_GetJointLinearVelocity(int64_t handle,
                                             int joint_idx,
                                             const float local_xyz[3],
                                             float out_world_vxyz[3])
{
    if (!local_xyz || !out_world_vxyz)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_dyn.find(handle);
    if (it == g_dyn.end())
        return CU_ERR_BAD_HANDLE;
    try {
        DynamicModel &m = *it->second;
        if (joint_idx < 0 || joint_idx >= m.get_armature().n_joints)
            return CU_ERR_INVALID_ARG;
        Eigen::Vector3f local(local_xyz[0], local_xyz[1], local_xyz[2]);
        Eigen::Vector3f v = m.get_linear_velocity(joint_idx, local);
        out_world_vxyz[0] = v.x();
        out_world_vxyz[1] = v.y();
        out_world_vxyz[2] = v.z();
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API int CU_Dynamic_GetJointLinearJacobian(int64_t handle,
                                             int joint_idx,
                                             const float local_xyz[3],
                                             float *out_j_row_major,
                                             int out_len)
{
    if (!local_xyz || !out_j_row_major)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_dyn.find(handle);
    if (it == g_dyn.end())
        return CU_ERR_BAD_HANDLE;
    try {
        DynamicModel &m = *it->second;
        const int d = vel_dim(m);
        if (out_len != 3 * d)
            return CU_ERR_INVALID_ARG;
        if (joint_idx < 0 || joint_idx >= m.get_armature().n_joints)
            return CU_ERR_INVALID_ARG;
        Eigen::Vector3f local(local_xyz[0], local_xyz[1], local_xyz[2]);
        Eigen::MatrixXf J = m.get_linear_Jacobian(joint_idx, local);
        if (J.rows() != 3 || J.cols() != d)
            return CU_ERR_EXCEPTION;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < d; c++) {
                out_j_row_major[r * d + c] = J(r, c);
            }
        }
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API int CU_Dynamic_GetJointLinearJacobianDot(int64_t handle,
                                                int joint_idx,
                                                const float local_xyz[3],
                                                float *out_jdot_row_major,
                                                int out_len)
{
    if (!local_xyz || !out_jdot_row_major)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_dyn.find(handle);
    if (it == g_dyn.end())
        return CU_ERR_BAD_HANDLE;
    try {
        DynamicModel &m = *it->second;
        const int d = vel_dim(m);
        if (out_len != 3 * d)
            return CU_ERR_INVALID_ARG;
        if (joint_idx < 0 || joint_idx >= m.get_armature().n_joints)
            return CU_ERR_INVALID_ARG;
        Eigen::Vector3f local(local_xyz[0], local_xyz[1], local_xyz[2]);
        Eigen::MatrixXf Jdot = m.get_linear_Jacobian_dot(joint_idx, local);
        if (Jdot.rows() != 3 || Jdot.cols() != d)
            return CU_ERR_EXCEPTION;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < d; c++) {
                out_jdot_row_major[r * d + c] = Jdot(r, c);
            }
        }
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

/* ---------- Kinematic ---------- */

CU_API int CU_Kinematic_Create(const char *armature_path_utf8, int64_t *out_handle)
{
    if (!out_handle || !armature_path_utf8 || armature_path_utf8[0] == '\0')
        return CU_ERR_INVALID_ARG;
    try {
        auto model = std::make_unique<KinematicModel>(std::string(armature_path_utf8));
        std::lock_guard<std::mutex> lock(g_mu);
        const int64_t id = g_next_id++;
        g_kin[id] = std::move(model);
        *out_handle = id;
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API void CU_Kinematic_Destroy(int64_t handle)
{
    std::lock_guard<std::mutex> lock(g_mu);
    g_kin.erase(handle);
}

static int kin_delta_dim(const KinematicModel &m)
{
    return m.get_armature().n_joints * 3 + 3;
}

CU_API int CU_Kinematic_GetNJoints(int64_t handle, int *out_n)
{
    if (!out_n)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_kin.find(handle);
    if (it == g_kin.end())
        return CU_ERR_BAD_HANDLE;
    *out_n = it->second->get_armature().n_joints;
    return CU_OK;
}

CU_API int CU_Kinematic_GetDeltaDim(int64_t handle, int *out_dim)
{
    if (!out_dim)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_kin.find(handle);
    if (it == g_kin.end())
        return CU_ERR_BAD_HANDLE;
    *out_dim = kin_delta_dim(*it->second);
    return CU_OK;
}

CU_API int CU_Kinematic_SetStateQ(int64_t handle,
                                   const float *joint_quat_wxyz,
                                   int joint_count,
                                   const float root_translation_xyz[3])
{
    if (!joint_quat_wxyz || !root_translation_xyz)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_kin.find(handle);
    if (it == g_kin.end())
        return CU_ERR_BAD_HANDLE;
    try {
        KinematicModel &m = *it->second;
        const int nj = m.get_armature().n_joints;
        if (joint_count != nj)
            return CU_ERR_INVALID_ARG;
        std::vector<Eigen::Quaternionf> pose;
        if (!copy_quats_in(pose, joint_quat_wxyz, joint_count * 4, nj))
            return CU_ERR_INVALID_ARG;
        Eigen::Vector3f tran(root_translation_xyz[0], root_translation_xyz[1], root_translation_xyz[2]);
        m.set_state_q(pose, tran);
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API int CU_Kinematic_GetStateQ(int64_t handle,
                                  float *joint_quat_wxyz,
                                  int joint_count,
                                  float root_translation_xyz[3])
{
    if (!joint_quat_wxyz || !root_translation_xyz)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_kin.find(handle);
    if (it == g_kin.end())
        return CU_ERR_BAD_HANDLE;
    try {
        KinematicModel &m = *it->second;
        const int nj = m.get_armature().n_joints;
        if (joint_count != nj)
            return CU_ERR_INVALID_ARG;
        std::vector<Eigen::Quaternionf> pose;
        Eigen::Vector3f tran;
        m.get_state_q(pose, tran);
        copy_quats_out(pose, joint_quat_wxyz, nj * 4);
        root_translation_xyz[0] = tran.x();
        root_translation_xyz[1] = tran.y();
        root_translation_xyz[2] = tran.z();
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

CU_API int CU_Kinematic_UpdateState(int64_t handle, const float *delta, int delta_len)
{
    if (!delta)
        return CU_ERR_INVALID_ARG;
    std::lock_guard<std::mutex> lock(g_mu);
    const auto it = g_kin.find(handle);
    if (it == g_kin.end())
        return CU_ERR_BAD_HANDLE;
    try {
        KinematicModel &m = *it->second;
        const int d = kin_delta_dim(m);
        if (delta_len != d)
            return CU_ERR_INVALID_ARG;
        Eigen::Map<const Eigen::VectorXf> dv(delta, d);
        m.update_state(dv);
        return CU_OK;
    } catch (...) {
        return CU_ERR_EXCEPTION;
    }
}

} // extern "C"
