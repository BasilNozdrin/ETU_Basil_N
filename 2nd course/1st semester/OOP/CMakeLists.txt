cmake_minimum_required(VERSION 3.17)
project(OOP)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE  src/main.cpp src/GameField/Field.cpp src/GameField/Field.h src/GameField/Cell.cpp src/GameField/Cell.h)
#set(SOURCE_LIB pngedit.cpp)

#find_package(PNG REQUIRED)

include_directories(.)
include_directories(bin)
#include_directories(${PNG_INCLUDE_DIR})

#add_library(pngedit SHARED ${SOURCE_LIB})

add_executable(OOP ${SOURCE_EXE} src/GameField/Field.cpp src/GameField/Field.h src/GameField/Cell.cpp src/GameField/Cell.h)

#target_link_libraries(OOP ${PNG_LIBRARY} pngedit)
