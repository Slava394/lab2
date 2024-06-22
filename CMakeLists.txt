cmake_minimum_required(VERSION 3.27)
project(lab2v1)

set(CMAKE_CXX_STANDARD 23)

find_path(READLINE_INCLUDE_DIR readline/readline.h)
find_library(READLINE_LIBRARY NAMES readline)

include_directories(${READLINE_INCLUDE_DIR})

if(NOT READLINE_INCLUDE_DIR OR NOT READLINE_LIBRARY)
    message(FATAL_ERROR "Readline library not found")
endif()

add_executable(
        lab2v1
        main.cpp
        header/DynamicArray.h
        header/LinkedList.h
        header/Sequence.h
        header/ArraySequence.h
        header/ListSequence.h
        test/MutableListSequenceTest.cpp
        test/MutableListSequenceTest.h
        test/ImmutableListSequenceTest.cpp
        test/ImmutableListSequenceTest.h
        test/MutableArraySequenceTest.cpp
        test/MutableArraySequenceTest.h
        test/ImmutableArraySequenceTest.cpp
        test/ImmutableArraySequenceTest.h
        header/BaseCollection.h
        interface/CLI.cpp
)

target_link_libraries(lab2v1 ${READLINE_LIBRARY})
