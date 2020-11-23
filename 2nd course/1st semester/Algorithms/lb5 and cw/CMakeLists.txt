cmake_minimum_required(VERSION 3.17)
project(lb5_and_cw)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE src/main.cpp
        modules/BinTree.hpp
        modules/Queue.hpp
        modules/WeakHeap.hpp)

include_directories(src)
include_directories(modules)

add_executable(lb5_and_cw ${SOURCE_EXE})
