cmake_minimum_required(VERSION 3.16)
project(Aufgabe4 C)

set(CMAKE_C_STANDARD 99)

add_executable(Aufgabe4_intergers integers.c)
add_executable(Aufgabe4_test test.c)
add_executable(Aufgabe4_persons persons.c)
add_executable(Aufgabe4_person_1 person_1.c)
add_executable(Aufgabe4_read_test read_test.c)
add_executable(Aufgabe4_calculator calculator.c operations.c operations.h)

