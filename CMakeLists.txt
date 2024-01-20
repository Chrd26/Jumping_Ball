cmake_minimum_required(VERSION 3.27)
project(jumping_physics)

set(CMAKE_CXX_STANDARD 20)

add_executable(jumping_physics main.cpp
        game.h
        gamelogic.cpp)

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(jumping_physics
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

find_package(SDL2_ttf CONFIG REQUIRED)
target_link_libraries(jumping_physics
        PRIVATE
        $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)