@echo off
setlocal

REM Build carticulate_unity.dll and copy to Unity Plugins folder.
REM Usage:
REM   build_unity_dll.bat
REM   build_unity_dll.bat "D:\path\to\carticulate_unity.dll"

set "SRC=%~dp0"
for %%I in ("%SRC%.") do set "SRC=%%~fI"
set "BUILD=%SRC%\build"

set "UNITY_DLL=D:\Projects\SchoolWorkProjects\firstPaperRalated\SIGGRAPH2024Unity\Assets\Plugins\X86_64\carticulate_unity.dll"
if not "%~1"=="" set "UNITY_DLL=%~1"

if not "%VCPKG_ROOT%"=="" (
  set "VCPKG=%VCPKG_ROOT%"
) else (
  set "VCPKG=D:\Tools\vcpkg"
)

echo [1/5] Checking required tools...
where cmake >nul 2>nul || goto :no_cmake
where git >nul 2>nul || goto :no_git

echo [2/5] Preparing vcpkg...
if not exist "%VCPKG%\vcpkg.exe" (
  echo vcpkg not found at "%VCPKG%". Installing...
  git clone https://github.com/microsoft/vcpkg "%VCPKG%" || goto :error
  call "%VCPKG%\bootstrap-vcpkg.bat" || goto :error
)

echo [3/5] Installing dependencies (manifest mode)...
"%VCPKG%\vcpkg.exe" install --triplet x64-windows --x-manifest-root="%SRC%" || goto :error

echo [4/5] Configuring and building carticulate_unity...
cmake -S "%SRC%" -B "%BUILD%" -G "Visual Studio 17 2022" -A x64 ^
  -DCMAKE_TOOLCHAIN_FILE="%VCPKG%\scripts\buildsystems\vcpkg.cmake" ^
  -DVCPKG_TARGET_TRIPLET=x64-windows ^
  -DCARTICULATE_BUILD_UNITY_PLUGIN=ON ^
  -DCARTICULATE_BUILD_PYBIND=OFF || goto :error

cmake --build "%BUILD%" --config Release --target carticulate_unity || goto :error

echo [5/5] Copying DLL to Unity...
for %%I in ("%UNITY_DLL%") do set "UNITY_DIR=%%~dpI"
if not exist "%UNITY_DIR%" mkdir "%UNITY_DIR%" || goto :error
set "FB=%UNITY_DIR%carticulate_unity_from_build.dll"
copy /Y "%BUILD%\Release\carticulate_unity.dll" "%UNITY_DLL%" >nul 2>&1
if errorlevel 1 (
  echo.
  echo 无法覆盖 "%UNITY_DLL%" （通常是因为 Unity 编辑器正在占用该 DLL）。
  echo 请先保存场景并关闭 Unity，然后重新运行本脚本；或手动替换。
  copy /Y "%BUILD%\Release\carticulate_unity.dll" "%FB%" >nul || goto :copy_fail
  echo.
  echo 已将新 DLL 复制到: "%FB%"
  echo 关闭 Unity 后，用该文件覆盖 carticulate_unity.dll 即可。
  echo.
  echo BUILD OK, COPY TO PLUGINS FOLDER NEEDS MANUAL STEP
  exit /b 0
)

echo.
echo SUCCESS: "%UNITY_DLL%"
exit /b 0

:copy_fail
echo ERROR: 无法写入 Plugins 目录（含临时文件 %FB%）。
exit /b 1

:no_cmake
echo ERROR: cmake not found in PATH.
echo Please install CMake and reopen terminal.
exit /b 1

:no_git
echo ERROR: git not found in PATH.
echo Please install Git and reopen terminal.
exit /b 1

:error
echo.
echo ERROR: Build failed.
exit /b 1
