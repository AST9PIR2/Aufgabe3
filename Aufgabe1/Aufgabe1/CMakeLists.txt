cmake_minimum_required(VERSION 3.16)
project(Aufgabe1 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS -Wall)
set(CMAKE_C_FLAGS -Werror)

add_executable(Aufgabe1_powerof2 powerof2.c)
add_executable(Aufgabe1_is_odd is_odd.c)
add_executable(Aufgabe1_pyramid.c pyramid.c)
add_executable(Aufgabe1_sum_loop.c sum_loop.c)
