cmake_minimum_required(VERSION 3.8)
project(postal_service)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)
add_executable(postal_service ${SOURCE_FILES})