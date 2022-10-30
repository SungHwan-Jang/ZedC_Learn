cmake_minimum_required(VERSION 3.24)
project(Debug_Macro C)

set(CMAKE_C_STANDARD 99)

add_executable(Debug_Macro main.c dbg.h)
