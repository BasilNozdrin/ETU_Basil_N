cmake_minimum_required(VERSION 3.17)
project(OOP)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE  main.cpp bin/gamefield/Field.cpp bin/gamefield/Field.h bin/gamefield/Cell.cpp bin/gamefield/Cell.h)
#set(SOURCE_LIB pngedit.cpp)

#find_package(PNG REQUIRED)

include_directories(.)
include_directories(bin)
#include_directories(${PNG_INCLUDE_DIR})

#add_library(pngedit SHARED ${SOURCE_LIB})

add_executable(OOP ${SOURCE_EXE} bin/gamefield/Field.cpp bin/gamefield/Field.h bin/gamefield/Cell.cpp bin/gamefield/Cell.h)

#target_link_libraries(OOP ${PNG_LIBRARY} pngedit)
