cmake_minimum_required(VERSION 3.14)
project(dicionario)

set(CMAKE_CXX_STANDARD 11)
include_directories(.)
add_executable(dicionario main.cpp prglib.h verbete.h verbete.cpp)