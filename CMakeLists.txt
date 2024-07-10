cmake_minimum_required(VERSION 3.27)
project("JumpingBall" LANGUAGES C VERSION 0.1 DESCRIPTION "Jumping Ball Physics Simulator")
set(SDL3_DIR "${PROJECT_SOURCE_DIR}/modules/SDL/build")
set(SDL3_ttf_DIR "${PROJECT_SOURCE_DIR}/modules/SDL_ttf/build")
set(liblocate_DIR "${PROJECT_SOURCE_DIR}/modules/cpplocate")

# Installation use otool -L to figure out rpath set rpath for macos with @loader_path
# set rpath for linux with @executable_path
# set(CMAKE_MACOXS_RPATH ON)
# set(CMAKE_INSTALL_RPATH "@loader_path/../../../lib")

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

add_executable(	${PROJECT_NAME} WIN32 ./src/main.c
				./src/app.h ./src/app.c ./src/resourcelocator.h
				./src/resourcelocator.c ./src/text.h ./src/text.c
				./src/results.h ./src/results.c ./src/textbox.h 
				./src/textbox.c ./src/ball.h ./src/ball.c 
                ./src/button.h ./src/button.c ${APP_FONT})


target_link_libraries(${PROJECT_NAME} PRIVATE cpplocate::liblocate)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
target_compile_definitions(${PROJECT_NAME} PUBLIC SDL_MAIN_USE_CALLBACKS)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3_ttf::SDL3_ttf)

set(CMAKE_INSTALL_PREFIX "Jumping Ball")
#message(${CMAKE_INSTALL_RPATH})
install(DIRECTORY "./modules/SDL/build/" DESTINATION "lib")
install(DIRECTORY "./modules/SDL_ttf/build/" DESTINATION "lib")
install(DIRECTORY "./modules/SDL/include/SDL3/" DESTINATION "include/SDL3")
install(DIRECTORY "./modules/SDL_ttf/include/SDL3_ttf/" DESTINATION "include/SDL3_ttf")
install(TARGETS "${PROJECT_NAME}" BUNDLE DESTINATION .)

include(CPack)
