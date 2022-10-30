cmake_minimum_required(VERSION 3.24)
project(Posix_ThreadTimer C)

set(CMAKE_C_STANDARD 99)

add_executable(Posix_ThreadTimer
        main.c
        runnable.c
        runnable.h
        runnable_cfg.h)
