#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SDL3_ttf::SDL3_ttf-shared" for configuration ""
set_property(TARGET SDL3_ttf::SDL3_ttf-shared APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SDL3_ttf::SDL3_ttf-shared PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_NOCONFIG "SDL3::SDL3-shared"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libSDL3_ttf.1.0.0.dylib"
  IMPORTED_SONAME_NOCONFIG "@rpath/libSDL3_ttf.1.0.0.dylib"
  )

list(APPEND _cmake_import_check_targets SDL3_ttf::SDL3_ttf-shared )
list(APPEND _cmake_import_check_files_for_SDL3_ttf::SDL3_ttf-shared "${_IMPORT_PREFIX}/lib/libSDL3_ttf.1.0.0.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
