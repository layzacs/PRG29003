cmake_minimum_required(VERSION 3.14)
project(dicionario)

set(CMAKE_CXX_STANDARD 14)

add_library(dicionario verbete.cpp verbete.h main.cpp prglib.h)