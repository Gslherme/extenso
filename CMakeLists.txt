cmake_minimum_required(VERSION 3.29)
project(extenso C)

set(CMAKE_C_STANDARD 11)

add_executable(extenso extenso.c)
add_executable(extenso_cli extenso_cli.c)
