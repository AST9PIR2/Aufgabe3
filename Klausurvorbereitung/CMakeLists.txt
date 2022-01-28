cmake_minimum_required(VERSION 3.16)
project(Klausurvorbereitung C)

set(CMAKE_C_STANDARD 99)

add_executable(Klausurvorbereitung_main main.c)
add_executable(Klausurvorbereitung_read_file read_file.c)
add_executable(Klausurvorbereitung_sort sort.c)
add_executable(Klausurvorbereitung_spielwiese spielwiese.c)