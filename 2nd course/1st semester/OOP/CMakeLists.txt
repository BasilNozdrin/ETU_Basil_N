cmake_minimum_required(VERSION 3.17)
project(OOP)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE
        src/main.cpp

        src/Buffs/Buff.h
        src/Buffs/Buff.cpp

        src/GameField/Cell.h
        src/GameField/Cell.cpp

        src/GameField/levels.cpp

        src/GameField/FieldRowIter.h
        src/GameField/FieldRowIter.cpp

        src/GameField/FieldIter.h
        src/GameField/FieldIter.cpp

        src/GameField/Field.h
        src/GameField/Field.cpp

        src/logic/Controls.h
        src/logic/Controls.cpp

        src/logic/Game.h
        src/logic/Game.cpp
        )


#set(SOURCE_LIB field.cpp)
#find_package(PNG REQUIRED)

include_directories(src)

#include_directories(${PNG_INCLUDE_DIR})
#add_library(field SHARED ${SOURCE_LIB})

add_executable(OOP ${SOURCE_EXE})

#target_link_libraries(OOP field)
#target_link_libraries(OOP ${PNG_LIBRARY} field)
