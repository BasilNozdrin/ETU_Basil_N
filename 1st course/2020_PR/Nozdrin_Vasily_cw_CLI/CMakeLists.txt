cmake_minimum_required(VERSION 3.16)

project(Nozdrin_Vasily_cw)

set(SOURCE_EXE  main.cpp)
set(SOURCE_LIB pngedit.cpp)

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})

add_library(pngedit SHARED ${SOURCE_LIB})
add_executable(Nozdrin_Vasily_cw ${SOURCE_EXE})

target_link_libraries(Nozdrin_Vasily_cw ${PNG_LIBRARY} pngedit)
