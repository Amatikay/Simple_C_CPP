cmake_minimum_required(VERSION 3.10)

project(TMP CXX C ASM)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)


add_executable(CPP
    CPP/main.cpp
    CPP/foo.cpp
)
set_target_properties(CPP PROPERTIES OUTPUT_NAME "cpp")

add_executable(C
    C/main.c
    C/foo.c
)
set_target_properties(C PROPERTIES OUTPUT_NAME "c")