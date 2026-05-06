#pragma once

/**
 * C API for Unity (P/Invoke). Quaternion layout: (w, x, y, z).
 * Generalized velocity / acceleration / force length: 3 + 3 * n_joints
 *   [0:3] root translation (world), [3+3*i : 6+3*i] axis-angle tangent per joint i.
 */

#include <stdint.h>

#if defined(_WIN32) && defined(CARTICULATE_UNITY_BUILDING)
#define CU_API __declspec(dllexport)
#elif defined(_WIN32)
#define CU_API __declspec(dllimport)
#else
#define CU_API __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define CU_OK 0
#define CU_ERR_INVALID_ARG (-1)
#define CU_ERR_BAD_HANDLE (-2)
#define CU_ERR_EXCEPTION (-3)

CU_API const char *CU_Version(void);

/* ---------- DynamicModel (physics) ---------- */

CU_API int CU_Dynamic_Create(const char *armature_path_utf8, int64_t *out_handle);
CU_API void CU_Dynamic_Destroy(int64_t handle);

CU_API int CU_Dynamic_GetNJoints(int64_t handle, int *out_n);
/** vel / acc / force vector length = 3 + 3 * n_joints */
CU_API int CU_Dynamic_GetVelDim(int64_t handle, int *out_dim);

/** joint_quat_wxyz length must be joint_count * 4 (w,x,y,z per joint). */
CU_API int CU_Dynamic_SetStateQ(int64_t handle,
                                 const float *joint_quat_wxyz,
                                 int joint_count,
                                 const float root_translation_xyz[3],
                                 const float *vel,
                                 int vel_len);

CU_API int CU_Dynamic_GetStateQ(int64_t handle,
                                 float *joint_quat_wxyz,
                                 int joint_count,
                                 float root_translation_xyz[3],
                                 float *vel,
                                 int vel_len);

CU_API int CU_Dynamic_UpdateState(int64_t handle, const float *acc, int acc_len, float delta_t);

CU_API int CU_Dynamic_ForwardDynamics(int64_t handle,
                                        const float *force,
                                        int force_len,
                                        float *out_acc,
                                        int acc_len);

CU_API int CU_Dynamic_GetJointWorldPosition(int64_t handle,
                                             int joint_idx,
                                             const float local_xyz[3],
                                             float out_world_xyz[3]);

CU_API int CU_Dynamic_GetJointWorldQuat(int64_t handle,
                                        int joint_idx,
                                        float out_wxyz[4]);

/** out_mass_row_major length must be vel_dim * vel_dim (row-major). */
CU_API int CU_Dynamic_GetMassMatrix(int64_t handle,
                                    float *out_mass_row_major,
                                    int out_len);

/** out_h length must be vel_dim. Equivalent to inverse_dynamics(acc=0). */
CU_API int CU_Dynamic_GetBiasForce(int64_t handle,
                                   float *out_h,
                                   int out_len);

/** out_force length must be vel_dim. */
CU_API int CU_Dynamic_InverseDynamics(int64_t handle,
                                      const float *acc,
                                      int acc_len,
                                      float *out_force,
                                      int out_len);

CU_API int CU_Dynamic_GetJointLinearVelocity(int64_t handle,
                                             int joint_idx,
                                             const float local_xyz[3],
                                             float out_world_vxyz[3]);

/** out_j_row_major length must be 3 * vel_dim (row-major). */
CU_API int CU_Dynamic_GetJointLinearJacobian(int64_t handle,
                                             int joint_idx,
                                             const float local_xyz[3],
                                             float *out_j_row_major,
                                             int out_len);

/** out_jdot_row_major length must be 3 * vel_dim (row-major). */
CU_API int CU_Dynamic_GetJointLinearJacobianDot(int64_t handle,
                                                int joint_idx,
                                                const float local_xyz[3],
                                                float *out_jdot_row_major,
                                                int out_len);

/* ---------- KinematicModel (no physics integration) ---------- */

CU_API int CU_Kinematic_Create(const char *armature_path_utf8, int64_t *out_handle);
CU_API void CU_Kinematic_Destroy(int64_t handle);

CU_API int CU_Kinematic_GetNJoints(int64_t handle, int *out_n);
/** delta length = 3 + 3 * n_joints (same layout as dynamic vel) */
CU_API int CU_Kinematic_GetDeltaDim(int64_t handle, int *out_dim);

CU_API int CU_Kinematic_SetStateQ(int64_t handle,
                                   const float *joint_quat_wxyz,
                                   int joint_count,
                                   const float root_translation_xyz[3]);

CU_API int CU_Kinematic_GetStateQ(int64_t handle,
                                   float *joint_quat_wxyz,
                                   int joint_count,
                                   float root_translation_xyz[3]);

CU_API int CU_Kinematic_UpdateState(int64_t handle, const float *delta, int delta_len);

#ifdef __cplusplus
}
#endif
