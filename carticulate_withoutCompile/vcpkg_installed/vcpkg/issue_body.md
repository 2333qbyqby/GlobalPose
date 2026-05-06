Package: g2o:x64-windows@2024-12-14#100

**Host Environment**

- Host: x64-windows
- Compiler: MSVC 19.44.35217.0
- CMake Version: 4.2.0-rc4
-    vcpkg-tool version: 2026-03-04-4b3e4c276b5b87a649e66341e11553e8c577459c
    vcpkg-scripts version: b5d1a94fb7 2026-03-27 (3 days ago)

**To Reproduce**

`vcpkg install `

**Failure logs**

```
-- Using cached RainerKuemmerle-g2o-eec325a1da1273e87bc97887d49e70570f28570c.tar.gz
-- Extracting source D:/Tools/vcpkg/downloads/RainerKuemmerle-g2o-eec325a1da1273e87bc97887d49e70570f28570c.tar.gz
-- Applying patch fix-absolute.patch
-- Applying patch eigen3-config-find.patch
-- Using source at D:/Tools/vcpkg/buildtrees/g2o/src/570f28570c-630732c038.clean
-- Configuring x64-windows
CMake Error at scripts/cmake/vcpkg_execute_required_process.cmake:127 (message):
    Command failed: D:\\Tools\\vcpkg\\downloads\\tools\\ninja-1.13.2-windows\\ninja.exe -v
    Working Directory: D:/Tools/vcpkg/buildtrees/g2o/x64-windows-rel/vcpkg-parallel-configure
    Error code: 1
    See logs for more information:
      D:\Tools\vcpkg\buildtrees\g2o\config-x64-windows-dbg-CMakeCache.txt.log
      D:\Tools\vcpkg\buildtrees\g2o\config-x64-windows-rel-CMakeCache.txt.log
      D:\Tools\vcpkg\buildtrees\g2o\config-x64-windows-dbg-CMakeConfigureLog.yaml.log
      D:\Tools\vcpkg\buildtrees\g2o\config-x64-windows-rel-CMakeConfigureLog.yaml.log
      D:\Tools\vcpkg\buildtrees\g2o\config-x64-windows-out.log

Call Stack (most recent call first):
  D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/share/vcpkg-cmake/vcpkg_cmake_configure.cmake:269 (vcpkg_execute_required_process)
  D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg-overlay-ports/g2o/portfile.cmake:16 (vcpkg_cmake_configure)
  scripts/ports.cmake:206 (include)



```

<details><summary>D:\Tools\vcpkg\buildtrees\g2o\config-x64-windows-out.log</summary>

```
[1/2] "D:/Tools/Cmake/bin/cmake.exe" -E chdir "../../x64-windows-dbg" "D:/Tools/Cmake/bin/cmake.exe" "D:/Tools/vcpkg/buildtrees/g2o/src/570f28570c-630732c038.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Debug" "-DCMAKE_INSTALL_PREFIX=D:/Tools/vcpkg/packages/g2o_x64-windows/debug" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DBUILD_LGPL_SHARED_LIBS=1" "-DG2O_BUILD_EXAMPLES=OFF" "-DG2O_BUILD_APPS=OFF" "-DG2O_BUILD_BENCHMARKS=OFF" "-DG2O_USE_CHOLMOD=OFF" "-DG2O_USE_CSPARSE=OFF" "-DG2O_USE_OPENGL=OFF" "-DG2O_USE_LOGGING=OFF" "-DG2O_BUILD_SLAM2D_TYPES=OFF" "-DG2O_BUILD_SLAM3D_TYPES=OFF" "-DCMAKE_MAKE_PROGRAM=D:\Tools\vcpkg\downloads\tools\ninja-1.13.2-windows\ninja.exe" "-DBUILD_SHARED_LIBS=ON" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=D:/Tools/vcpkg/scripts/toolchains/windows.cmake" "-DVCPKG_TARGET_TRIPLET=x64-windows" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=v143" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=D:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=D:/Tools/vcpkg" "-D_VCPKG_INSTALLED_DIR=D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
FAILED: [code=1] ../../x64-windows-dbg/CMakeCache.txt 
"D:/Tools/Cmake/bin/cmake.exe" -E chdir "../../x64-windows-dbg" "D:/Tools/Cmake/bin/cmake.exe" "D:/Tools/vcpkg/buildtrees/g2o/src/570f28570c-630732c038.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Debug" "-DCMAKE_INSTALL_PREFIX=D:/Tools/vcpkg/packages/g2o_x64-windows/debug" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DBUILD_LGPL_SHARED_LIBS=1" "-DG2O_BUILD_EXAMPLES=OFF" "-DG2O_BUILD_APPS=OFF" "-DG2O_BUILD_BENCHMARKS=OFF" "-DG2O_USE_CHOLMOD=OFF" "-DG2O_USE_CSPARSE=OFF" "-DG2O_USE_OPENGL=OFF" "-DG2O_USE_LOGGING=OFF" "-DG2O_BUILD_SLAM2D_TYPES=OFF" "-DG2O_BUILD_SLAM3D_TYPES=OFF" "-DCMAKE_MAKE_PROGRAM=D:\Tools\vcpkg\downloads\tools\ninja-1.13.2-windows\ninja.exe" "-DBUILD_SHARED_LIBS=ON" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=D:/Tools/vcpkg/scripts/toolchains/windows.cmake" "-DVCPKG_TARGET_TRIPLET=x64-windows" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=v143" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=D:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=D:/Tools/vcpkg" "-D_VCPKG_INSTALLED_DIR=D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
-- The C compiler identification is MSVC 19.44.35217.0
-- The CXX compiler identification is MSVC 19.44.35217.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: D:/VisualStudio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
...
Skipped 105 lines
...
FAILED: [code=1] ../CMakeCache.txt 
"D:/Tools/Cmake/bin/cmake.exe" -E chdir ".." "D:/Tools/Cmake/bin/cmake.exe" "D:/Tools/vcpkg/buildtrees/g2o/src/570f28570c-630732c038.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Release" "-DCMAKE_INSTALL_PREFIX=D:/Tools/vcpkg/packages/g2o_x64-windows" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DBUILD_LGPL_SHARED_LIBS=1" "-DG2O_BUILD_EXAMPLES=OFF" "-DG2O_BUILD_APPS=OFF" "-DG2O_BUILD_BENCHMARKS=OFF" "-DG2O_USE_CHOLMOD=OFF" "-DG2O_USE_CSPARSE=OFF" "-DG2O_USE_OPENGL=OFF" "-DG2O_USE_LOGGING=OFF" "-DG2O_BUILD_SLAM2D_TYPES=OFF" "-DG2O_BUILD_SLAM3D_TYPES=OFF" "-DCMAKE_MAKE_PROGRAM=D:\Tools\vcpkg\downloads\tools\ninja-1.13.2-windows\ninja.exe" "-DBUILD_SHARED_LIBS=ON" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=D:/Tools/vcpkg/scripts/toolchains/windows.cmake" "-DVCPKG_TARGET_TRIPLET=x64-windows" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=v143" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=D:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=D:/Tools/vcpkg" "-D_VCPKG_INSTALLED_DIR=D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
-- The C compiler identification is MSVC 19.44.35217.0
-- The CXX compiler identification is MSVC 19.44.35217.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: D:/VisualStudio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: D:/VisualStudio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Compiling on Windows
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - not found
-- Found Threads: TRUE
CMake Warning at D:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake:908 (_find_package):
  By not providing "Findnvpl.cmake" in CMAKE_MODULE_PATH this project has
  asked CMake to find a package configuration file provided by "nvpl", but
  CMake did not find one.

  Could not find a package configuration file provided by "nvpl" with any of
  the following names:

    nvplConfig.cmake
    nvpl-config.cmake

  Add the installation prefix of "nvpl" to CMAKE_PREFIX_PATH or set
  "nvpl_DIR" to a directory containing one of the above files.  If "nvpl"
  provides a separate development package or SDK, be sure it has been
  installed.
Call Stack (most recent call first):
  D:/Tools/Cmake/share/cmake-4.2/Modules/FindBLAS.cmake:1381 (find_package)
  D:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake:908 (_find_package)
  cmake_modules/FindSuiteSparse.cmake:293 (find_package)
  D:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake:908 (_find_package)
  CMakeLists.txt:98 (find_package)


-- Failed to find SuiteSparse - Did not find BLAS library (required for SuiteSparse).
CMake Warning at D:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake:908 (_find_package):
  By not providing "Findnvpl.cmake" in CMAKE_MODULE_PATH this project has
  asked CMake to find a package configuration file provided by "nvpl", but
  CMake did not find one.

  Could not find a package configuration file provided by "nvpl" with any of
  the following names:

    nvplConfig.cmake
    nvpl-config.cmake

  Add the installation prefix of "nvpl" to CMAKE_PREFIX_PATH or set
  "nvpl_DIR" to a directory containing one of the above files.  If "nvpl"
  provides a separate development package or SDK, be sure it has been
  installed.
Call Stack (most recent call first):
  D:/Tools/Cmake/share/cmake-4.2/Modules/FindBLAS.cmake:1381 (find_package)
  D:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake:908 (_find_package)
  D:/Tools/Cmake/share/cmake-4.2/Modules/FindLAPACK.cmake:275 (find_package)
  D:/Tools/Cmake/share/cmake-4.2/Modules/FindLAPACK.cmake:321 (_lapack_find_dependency)
  D:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake:908 (_find_package)
  cmake_modules/FindSuiteSparse.cmake:300 (find_package)
  D:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake:908 (_find_package)
  CMakeLists.txt:98 (find_package)


-- Failed to find SuiteSparse - Did not find LAPACK library (required for SuiteSparse).
-- Failed to find SuiteSparse - Did not find AMD header (required SuiteSparse component).
-- Failed to find SuiteSparse - Did not find AMD library (required SuiteSparse component).
-- Failed to find SuiteSparse - Did not find CAMD header (required SuiteSparse component).
-- Failed to find SuiteSparse - Did not find CAMD library (required SuiteSparse component).
-- Failed to find SuiteSparse - Did not find CCOLAMD header (required SuiteSparse component).
-- Failed to find SuiteSparse - Did not find CCOLAMD library (required SuiteSparse component).
-- Failed to find SuiteSparse - Did not find CHOLMOD header (required SuiteSparse component).
-- Failed to find SuiteSparse - Did not find CHOLMOD library (required SuiteSparse component).
-- Failed to find SuiteSparse - Did not find COLAMD header (required SuiteSparse component).
-- Failed to find SuiteSparse - Did not find COLAMD library (required SuiteSparse component).
-- Failed to find SuiteSparse - Did not find SPQR header (required SuiteSparse component).
-- Failed to find SuiteSparse - Did not find SPQR library (required SuiteSparse component).
-- Failed to find SuiteSparse - Did not find Config header (required SuiteSparse component).
-- Failed to find SuiteSparse - Did not find Config library (required SuiteSparse component).
-- Looking for shm_open in rt
-- Looking for shm_open in rt - not found
-- Failed to find some/all required components of SuiteSparse. (missing: SuiteSparse_AMD_INCLUDE_DIR SuiteSparse_AMD_LIBRARY SuiteSparse_CAMD_INCLUDE_DIR SuiteSparse_CAMD_LIBRARY SuiteSparse_CCOLAMD_INCLUDE_DIR SuiteSparse_CCOLAMD_LIBRARY SuiteSparse_CHOLMOD_INCLUDE_DIR SuiteSparse_CHOLMOD_LIBRARY SuiteSparse_COLAMD_INCLUDE_DIR SuiteSparse_COLAMD_LIBRARY SuiteSparse_SPQR_INCLUDE_DIR SuiteSparse_SPQR_LIBRARY SuiteSparse_Config_INCLUDE_DIR SuiteSparse_Config_LIBRARY AMD CAMD CCOLAMD CHOLMOD COLAMD SPQR Config) 
-- Disable support for Cholmod
-- Building LGPL code as a shared library
-- Could NOT find CSparse (missing: CSPARSE_INCLUDE_DIR CSPARSE_LIBRARY) 
-- Disable support for CSparse
-- Found OpenGL: opengl32
Qt5 not found. Install it and set Qt5_DIR accordingly
  In Windows, Qt5_DIR should be something like C:/Qt/5.4/msvc2013_64_opengl/lib/cmake/Qt5
-- Compiling with no built in types enabled
-- Compiling with MSVC
-- Performing Test HAVE_UNDERSCORE_PREFIXED_BESSEL_FUNCTIONS
-- Performing Test HAVE_UNDERSCORE_PREFIXED_BESSEL_FUNCTIONS - Success
CMake Error at D:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake:908 (_find_package):
  Could not find a configuration file for package "Eigen3" that is compatible
  with requested version "3.3".

  The following configuration files were considered but not accepted:

    D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/share/eigen3/Eigen3Config.cmake, version: 5.0.1
      The version found is not compatible with the version requested.

Call Stack (most recent call first):
  CMakeLists.txt:482 (find_package)


-- Configuring incomplete, errors occurred!
ninja: build stopped: subcommand failed.
```
</details>

<details><summary>D:\Tools\vcpkg\buildtrees\g2o\config-x64-windows-rel-CMakeCache.txt.log</summary>

```
# This is the CMakeCache file.
# For build in directory: d:/Tools/vcpkg/buildtrees/g2o/x64-windows-rel
# It was generated by CMake: D:/Tools/Cmake/bin/cmake.exe
# You can edit this file to change values found and used by cmake.
# If you do not want to change any of the values, simply exit the editor.
# If you do want to change a value, simply edit, save, and exit the editor.
# The syntax for the file is as follows:
# KEY:TYPE=VALUE
# KEY is the name of a variable in the cache.
# TYPE is a hint to GUIs for the type of VALUE, DO NOT EDIT TYPE!.
# VALUE is the current value for the KEY.

########################
# EXTERNAL cache entries
########################

//Path to a library.
BLAS_Accelerate_LIBRARY:FILEPATH=BLAS_Accelerate_LIBRARY-NOTFOUND

//Path to a library.
BLAS_acml_LIBRARY:FILEPATH=BLAS_acml_LIBRARY-NOTFOUND

//Path to a library.
BLAS_acml_mp_LIBRARY:FILEPATH=BLAS_acml_mp_LIBRARY-NOTFOUND

//Path to a library.
BLAS_armpl_lp64_LIBRARY:FILEPATH=BLAS_armpl_lp64_LIBRARY-NOTFOUND

//Path to a library.
BLAS_blas_LIBRARY:FILEPATH=BLAS_blas_LIBRARY-NOTFOUND

//Path to a library.
BLAS_blastrampoline_5_LIBRARY:FILEPATH=BLAS_blastrampoline_5_LIBRARY-NOTFOUND

//Path to a library.
BLAS_blis_LIBRARY:FILEPATH=BLAS_blis_LIBRARY-NOTFOUND

//Path to a library.
BLAS_complib_sgimath_LIBRARY:FILEPATH=BLAS_complib_sgimath_LIBRARY-NOTFOUND

//Path to a library.
BLAS_cxml_LIBRARY:FILEPATH=BLAS_cxml_LIBRARY-NOTFOUND

//Path to a library.
BLAS_dxml_LIBRARY:FILEPATH=BLAS_dxml_LIBRARY-NOTFOUND

//Path to a library.
BLAS_eml_LIBRARY:FILEPATH=BLAS_eml_LIBRARY-NOTFOUND

//Path to a library.
BLAS_essl_LIBRARY:FILEPATH=BLAS_essl_LIBRARY-NOTFOUND

//Path to a library.
BLAS_fjlapack_LIBRARY:FILEPATH=BLAS_fjlapack_LIBRARY-NOTFOUND

//Path to a library.
BLAS_flexiblas_LIBRARY:FILEPATH=BLAS_flexiblas_LIBRARY-NOTFOUND

//Path to a library.
BLAS_goto2_LIBRARY:FILEPATH=BLAS_goto2_LIBRARY-NOTFOUND

//Path to a library.
BLAS_mkl_intel_c_dll_LIBRARY:FILEPATH=BLAS_mkl_intel_c_dll_LIBRARY-NOTFOUND

//Path to a library.
BLAS_mkl_intel_lp64_dll_LIBRARY:FILEPATH=BLAS_mkl_intel_lp64_dll_LIBRARY-NOTFOUND

//Path to a library.
BLAS_mkl_rt_LIBRARY:FILEPATH=BLAS_mkl_rt_LIBRARY-NOTFOUND

//Path to a library.
BLAS_openblas_LIBRARY:FILEPATH=BLAS_openblas_LIBRARY-NOTFOUND

//Path to a library.
BLAS_scs_LIBRARY:FILEPATH=BLAS_scs_LIBRARY-NOTFOUND

//Path to a library.
BLAS_sgemm_LIBRARY:FILEPATH=BLAS_sgemm_LIBRARY-NOTFOUND

//Path to a library.
BLAS_sunperf_LIBRARY:FILEPATH=BLAS_sunperf_LIBRARY-NOTFOUND

//Path to a library.
BLAS_vecLib_LIBRARY:FILEPATH=BLAS_vecLib_LIBRARY-NOTFOUND

//Enable coverage reporting
BUILD_CODE_COVERAGE:BOOL=OFF

//No help, variable specified on the command line.
BUILD_LGPL_SHARED_LIBS:UNINITIALIZED=1

//Build Shared Libraries (preferred and required for the g2o plugin
// system)
BUILD_SHARED_LIBS:BOOL=ON

//Build with "-march native"
BUILD_WITH_MARCH_NATIVE:BOOL=OFF

//Path to a program.
CMAKE_AR:FILEPATH=D:/VisualStudio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/lib.exe

//Choose the type of build, options are: None Debug Release RelWithDebInfo
// MinSizeRel ...
CMAKE_BUILD_TYPE:STRING=Release

CMAKE_CROSSCOMPILING:STRING=OFF

//CXX compiler
CMAKE_CXX_COMPILER:FILEPATH=D:/VisualStudio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe

CMAKE_CXX_FLAGS:STRING=' /nologo /DWIN32 /D_WINDOWS /utf-8 /GR /EHsc /MP '

CMAKE_CXX_FLAGS_DEBUG:STRING='/MDd /Z7 /Ob0 /Od /RTC1 '

//Flags used by the CXX compiler during MINSIZEREL builds.
CMAKE_CXX_FLAGS_MINSIZEREL:STRING=/MD /O1 /Ob1 /DNDEBUG

CMAKE_CXX_FLAGS_RELEASE:STRING='/MD /O2 /Oi /Gy /DNDEBUG /Z7 '

//Flags used by the CXX compiler during RELWITHDEBINFO builds.
CMAKE_CXX_FLAGS_RELWITHDEBINFO:STRING=/MD /Zi /O2 /Ob1 /DNDEBUG

//Libraries linked by default with all C++ applications.
CMAKE_CXX_STANDARD_LIBRARIES:STRING=kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib

//C compiler
CMAKE_C_COMPILER:FILEPATH=D:/VisualStudio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe

...
Skipped 630 lines
...
CMAKE_EXPORT_COMPILE_COMMANDS-ADVANCED:INTERNAL=1
//Name of external makefile project generator.
CMAKE_EXTRA_GENERATOR:INTERNAL=
//Name of generator.
CMAKE_GENERATOR:INTERNAL=Ninja
//Generator instance identifier.
CMAKE_GENERATOR_INSTANCE:INTERNAL=
//Name of generator platform.
CMAKE_GENERATOR_PLATFORM:INTERNAL=
//Name of generator toolset.
CMAKE_GENERATOR_TOOLSET:INTERNAL=
//Test CMAKE_HAVE_LIBC_PTHREAD
CMAKE_HAVE_LIBC_PTHREAD:INTERNAL=
//Have library pthreads
CMAKE_HAVE_PTHREADS_CREATE:INTERNAL=
//Have library pthread
CMAKE_HAVE_PTHREAD_CREATE:INTERNAL=
//Source directory with the top level CMakeLists.txt file for this
// project
CMAKE_HOME_DIRECTORY:INTERNAL=D:/Tools/vcpkg/buildtrees/g2o/src/570f28570c-630732c038.clean
//ADVANCED property for variable: CMAKE_INSTALL_BINDIR
CMAKE_INSTALL_BINDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DATADIR
CMAKE_INSTALL_DATADIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DATAROOTDIR
CMAKE_INSTALL_DATAROOTDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DOCDIR
CMAKE_INSTALL_DOCDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_INCLUDEDIR
CMAKE_INSTALL_INCLUDEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_INFODIR
CMAKE_INSTALL_INFODIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LIBDIR
CMAKE_INSTALL_LIBDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LIBEXECDIR
CMAKE_INSTALL_LIBEXECDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LOCALEDIR
CMAKE_INSTALL_LOCALEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LOCALSTATEDIR
CMAKE_INSTALL_LOCALSTATEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_MANDIR
CMAKE_INSTALL_MANDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_OLDINCLUDEDIR
CMAKE_INSTALL_OLDINCLUDEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_RUNSTATEDIR
CMAKE_INSTALL_RUNSTATEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_SBINDIR
CMAKE_INSTALL_SBINDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_SHAREDSTATEDIR
CMAKE_INSTALL_SHAREDSTATEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_SYSCONFDIR
CMAKE_INSTALL_SYSCONFDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_LINKER
CMAKE_LINKER-ADVANCED:INTERNAL=1
//Name of CMakeLists files to read
CMAKE_LIST_FILE_NAME:INTERNAL=CMakeLists.txt
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS
CMAKE_MODULE_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_DEBUG
CMAKE_MODULE_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL
CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_RELEASE
CMAKE_MODULE_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MT
CMAKE_MT-ADVANCED:INTERNAL=1
//number of local generators
CMAKE_NUMBER_OF_MAKEFILES:INTERNAL=1
//Platform information initialized
CMAKE_PLATFORM_INFO_INITIALIZED:INTERNAL=1
//ADVANCED property for variable: CMAKE_POLICY_VERSION_MINIMUM
CMAKE_POLICY_VERSION_MINIMUM-ADVANCED:INTERNAL=1
//noop for ranlib
CMAKE_RANLIB:INTERNAL=:
//ADVANCED property for variable: CMAKE_RC_COMPILER
CMAKE_RC_COMPILER-ADVANCED:INTERNAL=1
CMAKE_RC_COMPILER_WORKS:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS
CMAKE_RC_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS_DEBUG
CMAKE_RC_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS_MINSIZEREL
CMAKE_RC_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS_RELEASE
CMAKE_RC_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS_RELWITHDEBINFO
CMAKE_RC_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//Path to CMake installation.
CMAKE_ROOT:INTERNAL=D:/Tools/Cmake/share/cmake-4.2
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS
CMAKE_SHARED_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_DEBUG
CMAKE_SHARED_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL
CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_RELEASE
CMAKE_SHARED_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SKIP_INSTALL_RPATH
CMAKE_SKIP_INSTALL_RPATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SKIP_RPATH
CMAKE_SKIP_RPATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS
CMAKE_STATIC_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_DEBUG
CMAKE_STATIC_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL
CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_RELEASE
CMAKE_STATIC_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_TOOLCHAIN_FILE
CMAKE_TOOLCHAIN_FILE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_VERBOSE_MAKEFILE
CMAKE_VERBOSE_MAKEFILE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_BINARY_7Z
CPACK_BINARY_7Z-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_BINARY_IFW
CPACK_BINARY_IFW-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_BINARY_INNOSETUP
CPACK_BINARY_INNOSETUP-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_BINARY_NSIS
CPACK_BINARY_NSIS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_BINARY_NUGET
CPACK_BINARY_NUGET-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_BINARY_WIX
CPACK_BINARY_WIX-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_BINARY_ZIP
CPACK_BINARY_ZIP-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_SOURCE_7Z
CPACK_SOURCE_7Z-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_SOURCE_ZIP
CPACK_SOURCE_ZIP-ADVANCED:INTERNAL=1
//ADVANCED property for variable: DISABLE_SSE2
DISABLE_SSE2-ADVANCED:INTERNAL=1
//ADVANCED property for variable: DISABLE_SSE3
DISABLE_SSE3-ADVANCED:INTERNAL=1
//ADVANCED property for variable: DISABLE_SSE4_1
DISABLE_SSE4_1-ADVANCED:INTERNAL=1
//ADVANCED property for variable: DISABLE_SSE4_2
DISABLE_SSE4_2-ADVANCED:INTERNAL=1
//ADVANCED property for variable: DISABLE_SSE4_A
DISABLE_SSE4_A-ADVANCED:INTERNAL=1
//Details about finding OpenGL
FIND_PACKAGE_MESSAGE_DETAILS_OpenGL:INTERNAL=[opengl32][ ][v()]
//Details about finding Threads
FIND_PACKAGE_MESSAGE_DETAILS_Threads:INTERNAL=[TRUE][v()]
//Have library rt
HAVE_LIBRT:INTERNAL=
//Test HAVE_UNDERSCORE_PREFIXED_BESSEL_FUNCTIONS
HAVE_UNDERSCORE_PREFIXED_BESSEL_FUNCTIONS:INTERNAL=1
//ADVANCED property for variable: OPENGL_gl_LIBRARY
OPENGL_gl_LIBRARY-ADVANCED:INTERNAL=1
//ADVANCED property for variable: OPENGL_glu_LIBRARY
OPENGL_glu_LIBRARY-ADVANCED:INTERNAL=1
//Install the dependencies listed in your manifest:
//\n    If this is off, you will have to manually install your dependencies.
//\n    See https://github.com/microsoft/vcpkg/tree/master/docs/specifications/manifests.md
// for more info.
//\n
VCPKG_MANIFEST_INSTALL:INTERNAL=OFF
//ADVANCED property for variable: VCPKG_VERBOSE
VCPKG_VERBOSE-ADVANCED:INTERNAL=1
//Making sure VCPKG_MANIFEST_MODE doesn't change
Z_VCPKG_CHECK_MANIFEST_MODE:INTERNAL=OFF
//Vcpkg root directory
Z_VCPKG_ROOT_DIR:INTERNAL=D:/Tools/vcpkg
//CMAKE_INSTALL_PREFIX during last run
_GNUInstallDirs_LAST_CMAKE_INSTALL_PREFIX:INTERNAL=D:/Tools/vcpkg/packages/g2o_x64-windows

```
</details>

<details><summary>D:\Tools\vcpkg\buildtrees\g2o\config-x64-windows-dbg-CMakeCache.txt.log</summary>

```
# This is the CMakeCache file.
# For build in directory: d:/Tools/vcpkg/buildtrees/g2o/x64-windows-dbg
# It was generated by CMake: D:/Tools/Cmake/bin/cmake.exe
# You can edit this file to change values found and used by cmake.
# If you do not want to change any of the values, simply exit the editor.
# If you do want to change a value, simply edit, save, and exit the editor.
# The syntax for the file is as follows:
# KEY:TYPE=VALUE
# KEY is the name of a variable in the cache.
# TYPE is a hint to GUIs for the type of VALUE, DO NOT EDIT TYPE!.
# VALUE is the current value for the KEY.

########################
# EXTERNAL cache entries
########################

//Path to a library.
BLAS_Accelerate_LIBRARY:FILEPATH=BLAS_Accelerate_LIBRARY-NOTFOUND

//Path to a library.
BLAS_acml_LIBRARY:FILEPATH=BLAS_acml_LIBRARY-NOTFOUND

//Path to a library.
BLAS_acml_mp_LIBRARY:FILEPATH=BLAS_acml_mp_LIBRARY-NOTFOUND

//Path to a library.
BLAS_armpl_lp64_LIBRARY:FILEPATH=BLAS_armpl_lp64_LIBRARY-NOTFOUND

//Path to a library.
BLAS_blas_LIBRARY:FILEPATH=BLAS_blas_LIBRARY-NOTFOUND

//Path to a library.
BLAS_blastrampoline_5_LIBRARY:FILEPATH=BLAS_blastrampoline_5_LIBRARY-NOTFOUND

//Path to a library.
BLAS_blis_LIBRARY:FILEPATH=BLAS_blis_LIBRARY-NOTFOUND

//Path to a library.
BLAS_complib_sgimath_LIBRARY:FILEPATH=BLAS_complib_sgimath_LIBRARY-NOTFOUND

//Path to a library.
BLAS_cxml_LIBRARY:FILEPATH=BLAS_cxml_LIBRARY-NOTFOUND

//Path to a library.
BLAS_dxml_LIBRARY:FILEPATH=BLAS_dxml_LIBRARY-NOTFOUND

//Path to a library.
BLAS_eml_LIBRARY:FILEPATH=BLAS_eml_LIBRARY-NOTFOUND

//Path to a library.
BLAS_essl_LIBRARY:FILEPATH=BLAS_essl_LIBRARY-NOTFOUND

//Path to a library.
BLAS_fjlapack_LIBRARY:FILEPATH=BLAS_fjlapack_LIBRARY-NOTFOUND

//Path to a library.
BLAS_flexiblas_LIBRARY:FILEPATH=BLAS_flexiblas_LIBRARY-NOTFOUND

//Path to a library.
BLAS_goto2_LIBRARY:FILEPATH=BLAS_goto2_LIBRARY-NOTFOUND

//Path to a library.
BLAS_mkl_intel_c_dll_LIBRARY:FILEPATH=BLAS_mkl_intel_c_dll_LIBRARY-NOTFOUND

//Path to a library.
BLAS_mkl_intel_lp64_dll_LIBRARY:FILEPATH=BLAS_mkl_intel_lp64_dll_LIBRARY-NOTFOUND

//Path to a library.
BLAS_mkl_rt_LIBRARY:FILEPATH=BLAS_mkl_rt_LIBRARY-NOTFOUND

//Path to a library.
BLAS_openblas_LIBRARY:FILEPATH=BLAS_openblas_LIBRARY-NOTFOUND

//Path to a library.
BLAS_scs_LIBRARY:FILEPATH=BLAS_scs_LIBRARY-NOTFOUND

//Path to a library.
BLAS_sgemm_LIBRARY:FILEPATH=BLAS_sgemm_LIBRARY-NOTFOUND

//Path to a library.
BLAS_sunperf_LIBRARY:FILEPATH=BLAS_sunperf_LIBRARY-NOTFOUND

//Path to a library.
BLAS_vecLib_LIBRARY:FILEPATH=BLAS_vecLib_LIBRARY-NOTFOUND

//Enable coverage reporting
BUILD_CODE_COVERAGE:BOOL=OFF

//No help, variable specified on the command line.
BUILD_LGPL_SHARED_LIBS:UNINITIALIZED=1

//Build Shared Libraries (preferred and required for the g2o plugin
// system)
BUILD_SHARED_LIBS:BOOL=ON

//Build with "-march native"
BUILD_WITH_MARCH_NATIVE:BOOL=OFF

//Path to a program.
CMAKE_AR:FILEPATH=D:/VisualStudio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/lib.exe

//Choose the type of build, options are: None Debug Release RelWithDebInfo
// MinSizeRel ...
CMAKE_BUILD_TYPE:STRING=Debug

CMAKE_CROSSCOMPILING:STRING=OFF

//CXX compiler
CMAKE_CXX_COMPILER:FILEPATH=D:/VisualStudio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe

CMAKE_CXX_FLAGS:STRING=' /nologo /DWIN32 /D_WINDOWS /utf-8 /GR /EHsc /MP '

CMAKE_CXX_FLAGS_DEBUG:STRING='/MDd /Z7 /Ob0 /Od /RTC1 '

//Flags used by the CXX compiler during MINSIZEREL builds.
CMAKE_CXX_FLAGS_MINSIZEREL:STRING=/MD /O1 /Ob1 /DNDEBUG

CMAKE_CXX_FLAGS_RELEASE:STRING='/MD /O2 /Oi /Gy /DNDEBUG /Z7 '

//Flags used by the CXX compiler during RELWITHDEBINFO builds.
CMAKE_CXX_FLAGS_RELWITHDEBINFO:STRING=/MD /Zi /O2 /Ob1 /DNDEBUG

//Libraries linked by default with all C++ applications.
CMAKE_CXX_STANDARD_LIBRARIES:STRING=kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib

//C compiler
...
Skipped 632 lines
...
CMAKE_EXPORT_COMPILE_COMMANDS-ADVANCED:INTERNAL=1
//Name of external makefile project generator.
CMAKE_EXTRA_GENERATOR:INTERNAL=
//Name of generator.
CMAKE_GENERATOR:INTERNAL=Ninja
//Generator instance identifier.
CMAKE_GENERATOR_INSTANCE:INTERNAL=
//Name of generator platform.
CMAKE_GENERATOR_PLATFORM:INTERNAL=
//Name of generator toolset.
CMAKE_GENERATOR_TOOLSET:INTERNAL=
//Test CMAKE_HAVE_LIBC_PTHREAD
CMAKE_HAVE_LIBC_PTHREAD:INTERNAL=
//Have library pthreads
CMAKE_HAVE_PTHREADS_CREATE:INTERNAL=
//Have library pthread
CMAKE_HAVE_PTHREAD_CREATE:INTERNAL=
//Source directory with the top level CMakeLists.txt file for this
// project
CMAKE_HOME_DIRECTORY:INTERNAL=D:/Tools/vcpkg/buildtrees/g2o/src/570f28570c-630732c038.clean
//ADVANCED property for variable: CMAKE_INSTALL_BINDIR
CMAKE_INSTALL_BINDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DATADIR
CMAKE_INSTALL_DATADIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DATAROOTDIR
CMAKE_INSTALL_DATAROOTDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DOCDIR
CMAKE_INSTALL_DOCDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_INCLUDEDIR
CMAKE_INSTALL_INCLUDEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_INFODIR
CMAKE_INSTALL_INFODIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LIBDIR
CMAKE_INSTALL_LIBDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LIBEXECDIR
CMAKE_INSTALL_LIBEXECDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LOCALEDIR
CMAKE_INSTALL_LOCALEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LOCALSTATEDIR
CMAKE_INSTALL_LOCALSTATEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_MANDIR
CMAKE_INSTALL_MANDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_OLDINCLUDEDIR
CMAKE_INSTALL_OLDINCLUDEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_RUNSTATEDIR
CMAKE_INSTALL_RUNSTATEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_SBINDIR
CMAKE_INSTALL_SBINDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_SHAREDSTATEDIR
CMAKE_INSTALL_SHAREDSTATEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_SYSCONFDIR
CMAKE_INSTALL_SYSCONFDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_LINKER
CMAKE_LINKER-ADVANCED:INTERNAL=1
//Name of CMakeLists files to read
CMAKE_LIST_FILE_NAME:INTERNAL=CMakeLists.txt
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS
CMAKE_MODULE_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_DEBUG
CMAKE_MODULE_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL
CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_RELEASE
CMAKE_MODULE_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MT
CMAKE_MT-ADVANCED:INTERNAL=1
//number of local generators
CMAKE_NUMBER_OF_MAKEFILES:INTERNAL=1
//Platform information initialized
CMAKE_PLATFORM_INFO_INITIALIZED:INTERNAL=1
//ADVANCED property for variable: CMAKE_POLICY_VERSION_MINIMUM
CMAKE_POLICY_VERSION_MINIMUM-ADVANCED:INTERNAL=1
//noop for ranlib
CMAKE_RANLIB:INTERNAL=:
//ADVANCED property for variable: CMAKE_RC_COMPILER
CMAKE_RC_COMPILER-ADVANCED:INTERNAL=1
CMAKE_RC_COMPILER_WORKS:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS
CMAKE_RC_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS_DEBUG
CMAKE_RC_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS_MINSIZEREL
CMAKE_RC_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS_RELEASE
CMAKE_RC_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RC_FLAGS_RELWITHDEBINFO
CMAKE_RC_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//Path to CMake installation.
CMAKE_ROOT:INTERNAL=D:/Tools/Cmake/share/cmake-4.2
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS
CMAKE_SHARED_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_DEBUG
CMAKE_SHARED_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL
CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_RELEASE
CMAKE_SHARED_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SKIP_INSTALL_RPATH
CMAKE_SKIP_INSTALL_RPATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SKIP_RPATH
CMAKE_SKIP_RPATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS
CMAKE_STATIC_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_DEBUG
CMAKE_STATIC_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL
CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_RELEASE
CMAKE_STATIC_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_TOOLCHAIN_FILE
CMAKE_TOOLCHAIN_FILE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_VERBOSE_MAKEFILE
CMAKE_VERBOSE_MAKEFILE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_BINARY_7Z
CPACK_BINARY_7Z-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_BINARY_IFW
CPACK_BINARY_IFW-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_BINARY_INNOSETUP
CPACK_BINARY_INNOSETUP-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_BINARY_NSIS
CPACK_BINARY_NSIS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_BINARY_NUGET
CPACK_BINARY_NUGET-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_BINARY_WIX
CPACK_BINARY_WIX-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_BINARY_ZIP
CPACK_BINARY_ZIP-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_SOURCE_7Z
CPACK_SOURCE_7Z-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CPACK_SOURCE_ZIP
CPACK_SOURCE_ZIP-ADVANCED:INTERNAL=1
//ADVANCED property for variable: DISABLE_SSE2
DISABLE_SSE2-ADVANCED:INTERNAL=1
//ADVANCED property for variable: DISABLE_SSE3
DISABLE_SSE3-ADVANCED:INTERNAL=1
//ADVANCED property for variable: DISABLE_SSE4_1
DISABLE_SSE4_1-ADVANCED:INTERNAL=1
//ADVANCED property for variable: DISABLE_SSE4_2
DISABLE_SSE4_2-ADVANCED:INTERNAL=1
//ADVANCED property for variable: DISABLE_SSE4_A
DISABLE_SSE4_A-ADVANCED:INTERNAL=1
//Details about finding OpenGL
FIND_PACKAGE_MESSAGE_DETAILS_OpenGL:INTERNAL=[opengl32][ ][v()]
//Details about finding Threads
FIND_PACKAGE_MESSAGE_DETAILS_Threads:INTERNAL=[TRUE][v()]
//Have library rt
HAVE_LIBRT:INTERNAL=
//Test HAVE_UNDERSCORE_PREFIXED_BESSEL_FUNCTIONS
HAVE_UNDERSCORE_PREFIXED_BESSEL_FUNCTIONS:INTERNAL=1
//ADVANCED property for variable: OPENGL_gl_LIBRARY
OPENGL_gl_LIBRARY-ADVANCED:INTERNAL=1
//ADVANCED property for variable: OPENGL_glu_LIBRARY
OPENGL_glu_LIBRARY-ADVANCED:INTERNAL=1
//Install the dependencies listed in your manifest:
//\n    If this is off, you will have to manually install your dependencies.
//\n    See https://github.com/microsoft/vcpkg/tree/master/docs/specifications/manifests.md
// for more info.
//\n
VCPKG_MANIFEST_INSTALL:INTERNAL=OFF
//ADVANCED property for variable: VCPKG_VERBOSE
VCPKG_VERBOSE-ADVANCED:INTERNAL=1
//Making sure VCPKG_MANIFEST_MODE doesn't change
Z_VCPKG_CHECK_MANIFEST_MODE:INTERNAL=OFF
//Vcpkg root directory
Z_VCPKG_ROOT_DIR:INTERNAL=D:/Tools/vcpkg
//CMAKE_INSTALL_PREFIX during last run
_GNUInstallDirs_LAST_CMAKE_INSTALL_PREFIX:INTERNAL=D:/Tools/vcpkg/packages/g2o_x64-windows/debug

```
</details>

<details><summary>D:\Tools\vcpkg\buildtrees\g2o\config-x64-windows-rel-CMakeConfigureLog.yaml.log</summary>

```

---
events:
  -
    kind: "message-v1"
    backtrace:
      - "D:/Tools/Cmake/share/cmake-4.2/Modules/CMakeDetermineSystem.cmake:212 (message)"
      - "CMakeLists.txt:6 (project)"
    message: |
      The system is: Windows - 10.0.19045 - AMD64
  -
    kind: "find-v1"
    backtrace:
      - "D:/Tools/Cmake/share/cmake-4.2/Modules/CMakeDetermineCompiler.cmake:63 (find_program)"
      - "D:/Tools/Cmake/share/cmake-4.2/Modules/CMakeDetermineCCompiler.cmake:64 (_cmake_find_compiler)"
      - "CMakeLists.txt:6 (project)"
    mode: "program"
    variable: "CMAKE_C_COMPILER"
    description: "C compiler"
    settings:
      SearchFramework: "LAST"
      SearchAppBundle: "LAST"
      CMAKE_FIND_USE_CMAKE_PATH: false
      CMAKE_FIND_USE_CMAKE_ENVIRONMENT_PATH: false
      CMAKE_FIND_USE_SYSTEM_ENVIRONMENT_PATH: true
      CMAKE_FIND_USE_CMAKE_SYSTEM_PATH: false
      CMAKE_FIND_USE_INSTALL_PREFIX: true
    names:
      - "cc"
      - "gcc"
      - "cl"
      - "bcc"
      - "xlc"
      - "icx"
      - "clang"
    candidate_directories:
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/VisualStudio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/VisualStudio/2022/Community/Common7/IDE/VC/vcpackages/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/VisualStudio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/TestWindow/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/VisualStudio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/TeamFoundation/Team Explorer/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/VisualStudio/2022/Community/MSBuild/Current/Bin/Roslyn/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/Program Files (x86)/Microsoft SDKs/Windows/v10.0A/bin/NETFX 4.8 Tools/x64/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/VisualStudio/2022/Community/Team Tools/DiagnosticsHub/Collector/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/Program Files (x86)/Windows Kits/10/bin/10.0.26100.0/x64/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/Program Files (x86)/Windows Kits/10/bin/x64/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/VisualStudio/2022/Community/MSBuild/Current/Bin/amd64/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/Windows/Microsoft.NET/Framework64/v4.0.30319/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/VisualStudio/2022/Community/Common7/IDE/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/VisualStudio/2022/Community/Common7/Tools/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/Tools/vcpkg/downloads/tools/powershell-core-7.5.4-windows/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/Windows/System32/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/Windows/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/Windows/System32/wbem/"
...
Skipped 30786 lines
...
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Program Files (x86)/Windows Kits/10/bin/x64/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Program Files (x86)/Windows Kits/10/bin/x64/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/MSBuild/Current/Bin/amd64/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/MSBuild/Current/Bin/amd64/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/Microsoft.NET/Framework64/v4.0.30319/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/Microsoft.NET/Framework64/v4.0.30319/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/Tools/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/Tools/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/Tools/vcpkg/downloads/tools/powershell-core-7.5.4-windows/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/Tools/vcpkg/downloads/tools/powershell-core-7.5.4-windows/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/wbem/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/wbem/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/WindowsPowerShell/v1.0/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/WindowsPowerShell/v1.0/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/OpenSSH/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/OpenSSH/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/Ninja/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/Ninja/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/VC/Linux/bin/ConnectionManagerExe/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/VC/Linux/bin/ConnectionManagerExe/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/VC/vcpkg/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/VC/vcpkg/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/Tools/vcpkg/downloads/tools/ninja-1.13.2-windows/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/Tools/vcpkg/downloads/tools/ninja-1.13.2-windows/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Program Files/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Program Files/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Program Files (x86)/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Program Files (x86)/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/Tools/Cmake/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/Tools/Cmake/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/Tools/vcpkg/packages/g2o_x64-windows/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/Tools/vcpkg/packages/g2o_x64-windows/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
    found: null
    search_context:
      CMAKE_PREFIX_PATH:
        - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows"
        - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug"
      ENV{PATH}:
        - "D:\\VisualStudio\\2022\\Community\\VC\\Tools\\MSVC\\14.44.35207\\bin\\HostX64\\x64"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\IDE\\VC\\VCPackages"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\IDE\\CommonExtensions\\Microsoft\\TestWindow"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\IDE\\CommonExtensions\\Microsoft\\TeamFoundation\\Team Explorer"
        - "D:\\VisualStudio\\2022\\Community\\MSBuild\\Current\\bin\\Roslyn"
        - "C:\\Program Files (x86)\\Microsoft SDKs\\Windows\\v10.0A\\bin\\NETFX 4.8 Tools\\x64\\"
        - "D:\\VisualStudio\\2022\\Community\\Team Tools\\DiagnosticsHub\\Collector"
        - "C:\\Program Files (x86)\\Windows Kits\\10\\bin\\10.0.26100.0\\\\x64"
        - "C:\\Program Files (x86)\\Windows Kits\\10\\bin\\\\x64"
        - "D:\\VisualStudio\\2022\\Community\\\\MSBuild\\Current\\Bin\\amd64"
        - "C:\\Windows\\Microsoft.NET\\Framework64\\v4.0.30319"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\IDE\\"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\Tools\\"
        - "D:\\Tools\\vcpkg\\downloads\\tools\\powershell-core-7.5.4-windows"
        - "C:\\Windows\\system32"
        - "C:\\Windows"
        - "C:\\Windows\\system32\\Wbem"
        - "C:\\Windows\\system32\\WindowsPowerShell\\v1.0\\"
        - "C:\\Windows\\system32\\OpenSSH\\"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\IDE\\CommonExtensions\\Microsoft\\CMake\\CMake\\bin"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\IDE\\CommonExtensions\\Microsoft\\CMake\\Ninja"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\IDE\\VC\\Linux\\bin\\ConnectionManagerExe"
        - "D:\\VisualStudio\\2022\\Community\\VC\\vcpkg"
        - "D:\\Tools\\vcpkg\\downloads\\tools\\ninja-1.13.2-windows"
      CMAKE_INSTALL_PREFIX: "D:/Tools/vcpkg/packages/g2o_x64-windows"
      CMAKE_SYSTEM_PREFIX_PATH:
        - "C:/Program Files"
        - "C:/Program Files (x86)"
        - "D:/Tools/Cmake"
        - "D:/Tools/vcpkg/packages/g2o_x64-windows"
      CMAKE_FIND_ROOT_PATH: "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows;D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug"
...
```
</details>

<details><summary>D:\Tools\vcpkg\buildtrees\g2o\config-x64-windows-dbg-CMakeConfigureLog.yaml.log</summary>

```

---
events:
  -
    kind: "message-v1"
    backtrace:
      - "D:/Tools/Cmake/share/cmake-4.2/Modules/CMakeDetermineSystem.cmake:212 (message)"
      - "CMakeLists.txt:6 (project)"
    message: |
      The system is: Windows - 10.0.19045 - AMD64
  -
    kind: "find-v1"
    backtrace:
      - "D:/Tools/Cmake/share/cmake-4.2/Modules/CMakeDetermineCompiler.cmake:63 (find_program)"
      - "D:/Tools/Cmake/share/cmake-4.2/Modules/CMakeDetermineCCompiler.cmake:64 (_cmake_find_compiler)"
      - "CMakeLists.txt:6 (project)"
    mode: "program"
    variable: "CMAKE_C_COMPILER"
    description: "C compiler"
    settings:
      SearchFramework: "LAST"
      SearchAppBundle: "LAST"
      CMAKE_FIND_USE_CMAKE_PATH: false
      CMAKE_FIND_USE_CMAKE_ENVIRONMENT_PATH: false
      CMAKE_FIND_USE_SYSTEM_ENVIRONMENT_PATH: true
      CMAKE_FIND_USE_CMAKE_SYSTEM_PATH: false
      CMAKE_FIND_USE_INSTALL_PREFIX: true
    names:
      - "cc"
      - "gcc"
      - "cl"
      - "bcc"
      - "xlc"
      - "icx"
      - "clang"
    candidate_directories:
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/VisualStudio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/VisualStudio/2022/Community/Common7/IDE/VC/vcpackages/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/VisualStudio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/TestWindow/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/VisualStudio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/TeamFoundation/Team Explorer/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/VisualStudio/2022/Community/MSBuild/Current/Bin/Roslyn/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/Program Files (x86)/Microsoft SDKs/Windows/v10.0A/bin/NETFX 4.8 Tools/x64/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/VisualStudio/2022/Community/Team Tools/DiagnosticsHub/Collector/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/Program Files (x86)/Windows Kits/10/bin/10.0.26100.0/x64/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/Program Files (x86)/Windows Kits/10/bin/x64/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/VisualStudio/2022/Community/MSBuild/Current/Bin/amd64/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/Windows/Microsoft.NET/Framework64/v4.0.30319/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/VisualStudio/2022/Community/Common7/IDE/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/VisualStudio/2022/Community/Common7/Tools/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/Tools/vcpkg/downloads/tools/powershell-core-7.5.4-windows/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/Windows/System32/"
      - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug/Windows/"
...
Skipped 30755 lines
...
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Program Files (x86)/Windows Kits/10/bin/10.0.26100.0/x64/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Program Files (x86)/Windows Kits/10/bin/10.0.26100.0/x64/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Program Files (x86)/Windows Kits/10/bin/x64/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Program Files (x86)/Windows Kits/10/bin/x64/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/MSBuild/Current/Bin/amd64/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/MSBuild/Current/Bin/amd64/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/Microsoft.NET/Framework64/v4.0.30319/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/Microsoft.NET/Framework64/v4.0.30319/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/Tools/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/Tools/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/Tools/vcpkg/downloads/tools/powershell-core-7.5.4-windows/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/Tools/vcpkg/downloads/tools/powershell-core-7.5.4-windows/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/wbem/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/wbem/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/WindowsPowerShell/v1.0/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/WindowsPowerShell/v1.0/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/OpenSSH/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Windows/System32/OpenSSH/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/Ninja/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/Ninja/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/VC/Linux/bin/ConnectionManagerExe/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/Common7/IDE/VC/Linux/bin/ConnectionManagerExe/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/VC/vcpkg/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/VisualStudio/2022/Community/VC/vcpkg/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/Tools/vcpkg/downloads/tools/ninja-1.13.2-windows/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/Tools/vcpkg/downloads/tools/ninja-1.13.2-windows/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Program Files/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Program Files/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Program Files (x86)/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "C:/Program Files (x86)/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/Tools/Cmake/Eigen3Config.cmake"
        mode: "config"
        reason: "no_exist"
      -
        path: "D:/Tools/Cmake/eigen3-config.cmake"
        mode: "config"
        reason: "no_exist"
    found: null
    search_context:
      CMAKE_PREFIX_PATH:
        - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug"
        - "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows"
      ENV{PATH}:
        - "D:\\VisualStudio\\2022\\Community\\VC\\Tools\\MSVC\\14.44.35207\\bin\\HostX64\\x64"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\IDE\\VC\\VCPackages"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\IDE\\CommonExtensions\\Microsoft\\TestWindow"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\IDE\\CommonExtensions\\Microsoft\\TeamFoundation\\Team Explorer"
        - "D:\\VisualStudio\\2022\\Community\\MSBuild\\Current\\bin\\Roslyn"
        - "C:\\Program Files (x86)\\Microsoft SDKs\\Windows\\v10.0A\\bin\\NETFX 4.8 Tools\\x64\\"
        - "D:\\VisualStudio\\2022\\Community\\Team Tools\\DiagnosticsHub\\Collector"
        - "C:\\Program Files (x86)\\Windows Kits\\10\\bin\\10.0.26100.0\\\\x64"
        - "C:\\Program Files (x86)\\Windows Kits\\10\\bin\\\\x64"
        - "D:\\VisualStudio\\2022\\Community\\\\MSBuild\\Current\\Bin\\amd64"
        - "C:\\Windows\\Microsoft.NET\\Framework64\\v4.0.30319"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\IDE\\"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\Tools\\"
        - "D:\\Tools\\vcpkg\\downloads\\tools\\powershell-core-7.5.4-windows"
        - "C:\\Windows\\system32"
        - "C:\\Windows"
        - "C:\\Windows\\system32\\Wbem"
        - "C:\\Windows\\system32\\WindowsPowerShell\\v1.0\\"
        - "C:\\Windows\\system32\\OpenSSH\\"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\IDE\\CommonExtensions\\Microsoft\\CMake\\CMake\\bin"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\IDE\\CommonExtensions\\Microsoft\\CMake\\Ninja"
        - "D:\\VisualStudio\\2022\\Community\\Common7\\IDE\\VC\\Linux\\bin\\ConnectionManagerExe"
        - "D:\\VisualStudio\\2022\\Community\\VC\\vcpkg"
        - "D:\\Tools\\vcpkg\\downloads\\tools\\ninja-1.13.2-windows"
      CMAKE_INSTALL_PREFIX: "D:/Tools/vcpkg/packages/g2o_x64-windows/debug"
      CMAKE_SYSTEM_PREFIX_PATH:
        - "C:/Program Files"
        - "C:/Program Files (x86)"
        - "D:/Tools/Cmake"
        - "D:/Tools/vcpkg/packages/g2o_x64-windows/debug"
      CMAKE_FIND_ROOT_PATH: "D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows/debug;D:/Projects/SchoolWorkProjects/firstPaperRalated/GlobalPose/carticulate_withoutCompile/vcpkg_installed/x64-windows"
...
```
</details>

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "$schema": "https://raw.githubusercontent.com/microsoft/vcpkg-tool/main/docs/vcpkg.schema.json",
  "name": "carticulate",
  "version": "0.1.0",
  "description": "carticulate C++: imu, dynamics, kinematics (Eigen, Sophus, g2o)",
  "dependencies": [
    "eigen3",
    "sophus",
    "g2o"
  ]
}

```
</details>
