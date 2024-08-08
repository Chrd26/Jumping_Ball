#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SDL3::SDL3-shared" for configuration ""
set_property(TARGET SDL3::SDL3-shared APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SDL3::SDL3-shared PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libSDL3.0.dylib"
  IMPORTED_SONAME_NOCONFIG "@rpath/libSDL3.0.dylib"
  )

list(APPEND _cmake_import_check_targets SDL3::SDL3-shared )
list(APPEND _cmake_import_check_files_for_SDL3::SDL3-shared "${_IMPORT_PREFIX}/lib/libSDL3.0.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
