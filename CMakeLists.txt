cmake_minimum_required(VERSION 3.21)
project(Yukon C)

set(CMAKE_C_STANDARD 11)

set(SDL2_INCLUDE_DIR C:/Development/libs/SDL/include)
set(SDL2_LIB_DIR C:/Development/libs/SDL/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(Yukon main.c Card.h Window.h CardView.h Ressources.h Column.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image)