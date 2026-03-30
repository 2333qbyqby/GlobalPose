using System;
using System.Runtime.InteropServices;

namespace Carticulate
{
    /// <summary>
    /// Build Release carticulate_unity.dll (CMake target carticulate_unity), copy to Assets/Plugins/x86_64/.
    /// Depends on MSVC runtime (VS 2022 redistributable) on the player machine.
    /// </summary>
    public static class Native
    {
        public const int Ok = 0;
        public const int ErrInvalidArg = -1;
        public const int ErrBadHandle = -2;
        public const int ErrException = -3;

#if UNITY_EDITOR_WIN || UNITY_STANDALONE_WIN
        const string Dll = "carticulate_unity";
#else
        const string Dll = "carticulate_unity";
#endif

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public static extern IntPtr CU_Version();

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public static extern int CU_Dynamic_Create(string armaturePathUtf8, out long handle);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern void CU_Dynamic_Destroy(long handle);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int CU_Dynamic_GetNJoints(long handle, out int n);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int CU_Dynamic_GetVelDim(long handle, out int dim);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int CU_Dynamic_SetStateQ(long handle, float[] jointQuatWxyz, int jointCount,
            float[] rootTranslationXyz, float[] vel, int velLen);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int CU_Dynamic_GetStateQ(long handle, float[] jointQuatWxyz, int jointCount,
            float[] rootTranslationXyz, float[] vel, int velLen);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int CU_Dynamic_UpdateState(long handle, float[] acc, int accLen, float deltaT);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int CU_Dynamic_ForwardDynamics(long handle, float[] force, int forceLen,
            float[] outAcc, int accLen);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int CU_Dynamic_GetJointWorldPosition(long handle, int jointIdx,
            float[] localXyz, float[] outWorldXyz);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int CU_Dynamic_GetJointWorldQuat(long handle, int jointIdx, float[] outWxyz);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public static extern int CU_Kinematic_Create(string armaturePathUtf8, out long handle);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern void CU_Kinematic_Destroy(long handle);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int CU_Kinematic_GetNJoints(long handle, out int n);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int CU_Kinematic_GetDeltaDim(long handle, out int dim);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int CU_Kinematic_SetStateQ(long handle, float[] jointQuatWxyz, int jointCount,
            float[] rootTranslationXyz);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int CU_Kinematic_GetStateQ(long handle, float[] jointQuatWxyz, int jointCount,
            float[] rootTranslationXyz);

        [DllImport(Dll, CallingConvention = CallingConvention.Cdecl)]
        public static extern int CU_Kinematic_UpdateState(long handle, float[] delta, int deltaLen);
    }
}
