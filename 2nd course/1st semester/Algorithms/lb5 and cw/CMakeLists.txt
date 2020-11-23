cmake_minimum_required(VERSION 3.17)
project(lb5_and_cw)

set(CMAKE_CXX_STANDARD 14)

include_directories(modules)
include_directories(src)

add_executable(lb5_and_cw
        modules/BinTree.hpp
        modules/Queue.hpp
        modules/WeakHeap.hpp
        src/main.cpp
        CMakeLists.txt
        lb5_and_cw)
