cmake_minimum_required(VERSION 3.16)
project(Aufgabe2 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS -Wall)
set(CMAKE_C_FLAGS -Werror)

add_executable(Aufgabe2_pyramid2 pyramid2.c)
add_executable(Aufgabe2_calculator calculator.c operations.c operations.h)
add_executable(Aufgabe2_prime prime.c is_prime.c is_prime.h)



