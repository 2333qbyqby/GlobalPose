#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "g2o::stuff" for configuration "Debug"
set_property(TARGET g2o::stuff APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::stuff PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/g2o_stuff.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/g2o_stuff.dll"
  )

list(APPEND _cmake_import_check_targets g2o::stuff )
list(APPEND _cmake_import_check_files_for_g2o::stuff "${_IMPORT_PREFIX}/debug/lib/g2o_stuff.lib" "${_IMPORT_PREFIX}/debug/bin/g2o_stuff.dll" )

# Import target "g2o::core" for configuration "Debug"
set_property(TARGET g2o::core APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::core PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/g2o_core.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/g2o_core.dll"
  )

list(APPEND _cmake_import_check_targets g2o::core )
list(APPEND _cmake_import_check_files_for_g2o::core "${_IMPORT_PREFIX}/debug/lib/g2o_core.lib" "${_IMPORT_PREFIX}/debug/bin/g2o_core.dll" )

# Import target "g2o::solver_pcg" for configuration "Debug"
set_property(TARGET g2o::solver_pcg APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::solver_pcg PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/g2o_solver_pcg.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/g2o_solver_pcg.dll"
  )

list(APPEND _cmake_import_check_targets g2o::solver_pcg )
list(APPEND _cmake_import_check_files_for_g2o::solver_pcg "${_IMPORT_PREFIX}/debug/lib/g2o_solver_pcg.lib" "${_IMPORT_PREFIX}/debug/bin/g2o_solver_pcg.dll" )

# Import target "g2o::solver_dense" for configuration "Debug"
set_property(TARGET g2o::solver_dense APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::solver_dense PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/g2o_solver_dense.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/g2o_solver_dense.dll"
  )

list(APPEND _cmake_import_check_targets g2o::solver_dense )
list(APPEND _cmake_import_check_files_for_g2o::solver_dense "${_IMPORT_PREFIX}/debug/lib/g2o_solver_dense.lib" "${_IMPORT_PREFIX}/debug/bin/g2o_solver_dense.dll" )

# Import target "g2o::solver_structure_only" for configuration "Debug"
set_property(TARGET g2o::solver_structure_only APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::solver_structure_only PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/g2o_solver_structure_only.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/g2o_solver_structure_only.dll"
  )

list(APPEND _cmake_import_check_targets g2o::solver_structure_only )
list(APPEND _cmake_import_check_files_for_g2o::solver_structure_only "${_IMPORT_PREFIX}/debug/lib/g2o_solver_structure_only.lib" "${_IMPORT_PREFIX}/debug/bin/g2o_solver_structure_only.dll" )

# Import target "g2o::solver_eigen" for configuration "Debug"
set_property(TARGET g2o::solver_eigen APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(g2o::solver_eigen PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/g2o_solver_eigen.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/g2o_solver_eigen.dll"
  )

list(APPEND _cmake_import_check_targets g2o::solver_eigen )
list(APPEND _cmake_import_check_files_for_g2o::solver_eigen "${_IMPORT_PREFIX}/debug/lib/g2o_solver_eigen.lib" "${_IMPORT_PREFIX}/debug/bin/g2o_solver_eigen.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
