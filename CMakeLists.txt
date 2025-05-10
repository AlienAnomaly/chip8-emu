cmake_minimum_required(VERSION 3.25)

project(chip8)

include_directories(headers)

add_executable(chip8 
    src/main.cpp
    src/sdl_context.cpp
    src/machine.cpp)

target_link_libraries(chip8 PRIVATE SDL3)