cmake_minimum_required(VERSION 3.16)
project(Assignment5)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment5 main.cpp)
add_executable(test utf8.c utf8.h testUTF8string.cpp UTF8string.cpp UTF8string.hpp)
