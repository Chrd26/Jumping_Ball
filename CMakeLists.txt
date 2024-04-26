# this is a cmake list
cmake_minimum_required(VERSION 3.27)
project("JumpingBall" LANGUAGES C VERSION 0.1 DESCRIPTION "Jumping Ball Physics Simulator")

add_executable(${PROJECT_NAME} ./src/main.c)
