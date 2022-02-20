cmake_minimum_required(VERSION 3.17)
project(lab6)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE
        main.cpp
        linear.cpp
        Matrix.hpp
        )

#set(SOURCE_LIB field.cpp)
#find_package(PNG REQUIRED)

#include_directories(${PNG_INCLUDE_DIR})
#add_library(field SHARED ${SOURCE_LIB})

add_executable(lab6 ${SOURCE_EXE})

#target_link_libraries(OOP field)
#target_link_libraries(OOP ${PNG_LIBRARY} field)