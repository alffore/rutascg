cmake_minimum_required(VERSION 3.10)
project(rutacg C)

set(CMAKE_C_STANDARD 99)

add_executable(rutacg main.c rutacg.h algoritmo.c salida.c algortimofb.c)
target_link_libraries(rutacg m)
