cmake_minimum_required(VERSION 3.20)
project(part_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(part_1
        ex2.c
        ex2.h
        main1.c)
