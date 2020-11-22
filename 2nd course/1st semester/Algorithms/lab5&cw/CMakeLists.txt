cmake_minimum_required(VERSION 3.15)
project(lab5_CW)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE src/main.cpp modules/BinTree.hpp modules/Queue.hpp modules/WeakHeap.hpp)

include_directories(src)
include_directories(modules)

add_executable(lab5_CW ${SOURCE_EXE})
