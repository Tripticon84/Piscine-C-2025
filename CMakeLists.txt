cmake_minimum_required(VERSION 3.0)
project(Nocturne C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH ${CMAKE_SOURCE_DIR}/src/include/SDL)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(Nocturne src/main.c
        src/game/game.c
        src/game/game.h
        src/directory/display.c
        src/directory/display.h
        src/config/config.c
        src/config/config.h
        src/board/board.c
        src/board/board.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})