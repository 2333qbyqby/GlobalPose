cmake_minimum_required(VERSION 3.16)

project(carticulate
  VERSION 0.1.0
  LANGUAGES CXX)

option(CARTICULATE_BUILD_PYBIND "Build Python extension (carticulate module)" OFF)
option(CARTICULATE_BUILD_UNITY_PLUGIN "Build carticulate_unity.dll for Unity P/Invoke" ON)
option(CARTICULATE_USE_DIAGONAL_INERTIA "USE_DIAGONAL_INERTIA for DynamicArmature file format" OFF)
option(CARTICULATE_ENABLE_INSTALL "Install headers and libraries" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
  cmake_policy(SET CMP0091 NEW)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

find_package(Eigen3 CONFIG REQUIRED)

find_package(Sophus CONFIG REQUIRED)

find_package(g2o CONFIG REQUIRED)

find_package(fmt CONFIG QUIET)
if(TARGET fmt::fmt)
  set(CARTICULATE_FMT_TARGET fmt::fmt)
endif()

# vcpkg / older Sophus: ALIAS may be missing
if(NOT TARGET Sophus::Sophus AND TARGET Sophus)
  add_library(Sophus::Sophus ALIAS Sophus)
endif()

# ---------- imu ----------
add_library(carticulate_imu STATIC
  imu/detector.cpp
  imu/eskf_imu.cpp)
target_include_directories(carticulate_imu PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/imu")
target_link_libraries(carticulate_imu PUBLIC Eigen3::Eigen Sophus::Sophus)

# ---------- dynamics ----------
add_library(carticulate_dynamics STATIC
  dynamics/dynamic_armature.cpp
  dynamics/dynamic_model.cpp)
target_include_directories(carticulate_dynamics PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/dynamics")
target_link_libraries(carticulate_dynamics PUBLIC Eigen3::Eigen Sophus::Sophus)
target_compile_definitions(carticulate_dynamics PUBLIC
  GLOG_NO_ABBREVIATED_SEVERITIES
  NOMINMAX)
if(CARTICULATE_USE_DIAGONAL_INERTIA)
  target_compile_definitions(carticulate_dynamics PUBLIC USE_DIAGONAL_INERTIA)
endif()

# ---------- kinematics ----------
add_library(carticulate_kinematics STATIC
  kinematics/kinematic_armature.cpp
  kinematics/kinematic_model.cpp
  kinematics/kinematic_optimizer.cpp)
target_include_directories(carticulate_kinematics PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/kinematics")
target_compile_definitions(carticulate_kinematics PUBLIC
  GLOG_NO_ABBREVIATED_SEVERITIES
  NOMINMAX)
target_link_libraries(carticulate_kinematics PUBLIC
  Eigen3::Eigen
  Sophus::Sophus
  g2o::core
  g2o::stuff)

# Optional dense linear solver library (layout varies by g2o packaging)
foreach(_t IN ITEMS g2o::solver_dense g2o::solver_eigen)
  if(TARGET ${_t})
    target_link_libraries(carticulate_kinematics PUBLIC ${_t})
    break()
  endif()
endforeach()

if(CARTICULATE_FMT_TARGET)
  target_link_libraries(carticulate_kinematics PUBLIC ${CARTICULATE_FMT_TARGET})
endif()

# ---------- Python pybind extension (optional) ----------
if(CARTICULATE_BUILD_UNITY_PLUGIN)
  add_library(carticulate_unity SHARED
    unity_bridge/carticulate_unity.cpp)
  target_include_directories(carticulate_unity PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/unity_bridge"
    "${CMAKE_CURRENT_SOURCE_DIR}")
  target_link_libraries(carticulate_unity PRIVATE
    carticulate_dynamics
    carticulate_kinematics)
  target_compile_definitions(carticulate_unity PRIVATE
    CARTICULATE_UNITY_BUILDING
    GLOG_NO_ABBREVIATED_SEVERITIES
    NOMINMAX)
endif()

if(CARTICULATE_BUILD_PYBIND)
  find_package(Python 3.8 COMPONENTS Interpreter Development.Module REQUIRED)
  find_package(pybind11 CONFIG REQUIRED)
  pybind11_add_module(carticulate MODULE
    pybind/pybind.cpp
    pybind/utils.cpp)
  target_include_directories(carticulate PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/pybind")
  target_link_libraries(carticulate PRIVATE
    carticulate_kinematics
    carticulate_dynamics
    carticulate_imu)
  target_compile_definitions(carticulate PRIVATE
    GLOG_NO_ABBREVIATED_SEVERITIES
    NOMINMAX)
  if(MSVC)
    target_compile_options(carticulate PRIVATE /bigobj)
  endif()
endif()

# ---------- install ----------
if(CARTICULATE_ENABLE_INSTALL)
  include(GNUInstallDirs)
  install(TARGETS carticulate_imu carticulate_dynamics carticulate_kinematics
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
  install(DIRECTORY imu/ dynamics/ kinematics/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/carticulate
    FILES_MATCHING PATTERN "*.h")
endif()
