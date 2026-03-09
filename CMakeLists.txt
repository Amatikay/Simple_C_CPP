cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)

project(Simple_C_CPP CXX C ASM)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

enable_testing()

add_subdirectory(Test)
add_subdirectory(C)
add_subdirectory(CPP)