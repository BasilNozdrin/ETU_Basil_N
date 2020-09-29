cmake_minimum_required(VERSION 3.17)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test main.cpp A.cpp A.h AA.cpp AA.h AARowIter.cpp AARowIter.h)