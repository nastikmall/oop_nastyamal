cmake_minimum_required(VERSION 3.25)
project(lab0)

set(CMAKE_CXX_STANDARD 17)

find_program(CLANG_TIDY clang-tidy)

if (CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY $ {CLANG_TIDY})
endif ()

add_executable(
        lab0 main.cpp
        comparator.cpp
        word_counter.cpp
        word_counter.h
)