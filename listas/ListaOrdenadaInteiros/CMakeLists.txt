cmake_minimum_required(VERSION 3.14)
project(Prog)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)
include_directories(googletest/include googletest .)

add_executable(runTest test.cpp prglib.h questao.cpp questao.h)

target_link_libraries(runTest gtest gtest_main)
