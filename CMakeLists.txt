cmake_minimum_required(VERSION 4.0)
project(Nocturne C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH ${CMAKE_SOURCE_DIR}/src/include/SDL)
set(SDL2_TTF_PATH ${CMAKE_SOURCE_DIR}/src/include/SDL)


find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)


include_directories(${SDL2_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})


add_executable(Nocturne src/main.c
        src/game.c
        src/include/game.h
        src/display.c
        src/include/display.h
        src/config.c
        src/include/config.h
        src/board.c
        src/menu.c
        src/include/menu.h
        src/local_mode.c
        src/include/local_mode.h
        src/place.c
        src/include/place.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY})