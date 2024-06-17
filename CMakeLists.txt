cmake_minimum_required(VERSION 3.27)
project("JumpingBall" LANGUAGES C VERSION 0.1 DESCRIPTION "Jumping Ball Physics Simulator")
set(SDL3_DIR "${PROJECT_SOURCE_DIR}/modules/SDL/build")
set(SDL3_ttf_DIR "${PROJECT_SOURCE_DIR}/modules/SDL_ttf/build")
set(liblocate_DIR "${PROJECT_SOURCE_DIR}/modules/cpplocate")
set(CMAKE_FIND_FRAMEWORK FIRST)

# Handle Submodules: https://cliutils.gitlab.io/modern-cmake/chapters/projects/submodule.html 
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY "./modules/"
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

# Has SDL been downloaded?
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/modules/SDL/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

# Has SDL_ttf been downloaded?
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/modules/SDL_ttf/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

# Has cpplocate been downloaded?
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/modules/cpplocate/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_subdirectory("${PROJECT_SOURCE_DIR}/modules/SDL")
add_subdirectory("${PROJECT_SOURCE_DIR}/modules/SDL_ttf")
add_subdirectory("${PROJECT_SOURCE_DIR}/modules/cpplocate")

find_package(SDL3_ttf REQUIRED CONFIG REQUIRED COMPONENTS SDL3_ttf)
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)
find_package(liblocate REQUIRED CONFIG REQUIRED COMPONENTS liblocate)

file(GLOB APP_FONT "./fonts/Montserrat-VariableFont_wght.ttf")
file(GLOB MACOS_ICON "./packaging assets/img/Jumping_Ball_Logo.icns")
file(GLOB_RECURSE SDL_LIB_FILES "./modules/SDL/build/*.dylib")
file(GLOB_RECURSE SDL_TTF_LIB_FILES "./modules/SDL_ttf/build/*.dylib")
file(GLOB_RECURSE LIBLOCATE_LIB_FILES "./modules/cpplocate/build/*.dylib")

add_executable(	${PROJECT_NAME} MACOSX_BUNDLE ./src/main.c
				./src/app.h ./src/app.c ./src/resourcelocator.h
				./src/resourcelocator.c ./src/text.h ./src/text.c
				./src/results.h ./src/results.c ./src/textbox.h 
				./src/textbox.c ./src/ball.h ./src/ball.c 
                ./src/button.h ./src/button.c ${APP_FONT} ${MACOS_ICON})

            
# Set macos Icon
file(RELATIVE_PATH RES_PATH_NAME "${CMAKE_CURRENT_SOURCE_DIR}" ${MACOS_ICON})
get_filename_component(NEW_FILE_PATH_NAME ${RES_PATH_NAME} DIRECTORY)
set_property(SOURCE ${MACOS_ICON} PROPERTY MACOSX_PACKAGE_LOCATION "Resources/${NEW_FILE_PATH_NAME}")
set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_ICON_FILE "Contents/Resources/packaging assets/img/Jumping_Ball_Logo.icns")

#  Include font to the .app bundle
file(RELATIVE_PATH RES_PATH_NAME "${CMAKE_CURRENT_SOURCE_DIR}" ${APP_FONT})
get_filename_component(NEW_FILE_PATH_NAME ${RES_PATH_NAME} DIRECTORY)
set_property(SOURCE ${APP_FONT} PROPERTY MACOSX_PACKAGE_LOCATION "Resources/${NEW_FILE_PATH_NAME}")

# include SDL library to the bundle
foreach(RESOURCE ${SDL_LIB_FILES})
    file(RELATIVE_PATH RES_PATH_NAME "${CMAKE_CURRENT_SOURCE_DIR}" ${RESOURCE})
	get_filename_component(NEW_FILE_PATH_NAME ${RES_PATH_NAME} DIRECTORY)
    set_property(SOURCE ${RESOURCE} PROPERTY MACOSX_PACKAGE_LOCATION "Frameworks/${NEW_FILE_PATH_NAME}")
endforeach()
# include SDL ttf library to the bundle
foreach(RESOURCE ${SDL_TTF_LIB_FILES})
    file(RELATIVE_PATH RES_PATH_NAME "${CMAKE_CURRENT_SOURCE_DIR}" ${RESOURCE})
	get_filename_component(NEW_FILE_PATH_NAME ${RES_PATH_NAME} DIRECTORY)
    set_property(SOURCE ${RESOURCE} PROPERTY MACOSX_PACKAGE_LOCATION "Frameworks/${NEW_FILE_PATH_NAME}")
endforeach()
# include cpplocate library to the bundle
foreach(RESOURCE ${LIBLOCATE_LIB_FILES})
    file(RELATIVE_PATH RES_PATH_NAME "${CMAKE_CURRENT_SOURCE_DIR}" ${RESOURCE})
	get_filename_component(NEW_FILE_PATH_NAME ${RES_PATH_NAME} DIRECTORY)
    set_property(SOURCE ${RESOURCE} PROPERTY MACOSX_PACKAGE_LOCATION "Frameworks/${NEW_FILE_PATH_NAME}")
endforeach()

target_link_libraries(${PROJECT_NAME} PRIVATE cpplocate::liblocate)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3_ttf::SDL3_ttf)
install(TARGETS ${PROJECT_NAME} BUNDLE DESTINATION .)
include(CPack)
