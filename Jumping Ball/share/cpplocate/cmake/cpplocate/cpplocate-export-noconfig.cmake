#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cpplocate::cpplocate" for configuration ""
set_property(TARGET cpplocate::cpplocate APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(cpplocate::cpplocate PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libcpplocate.2.3.0.dylib"
  IMPORTED_SONAME_NOCONFIG "@rpath/libcpplocate.2.dylib"
  )

list(APPEND _cmake_import_check_targets cpplocate::cpplocate )
list(APPEND _cmake_import_check_files_for_cpplocate::cpplocate "${_IMPORT_PREFIX}/lib/libcpplocate.2.3.0.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
