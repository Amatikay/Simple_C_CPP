cmake_minimum_required(VERSION 3.10)

project(Simple_C_CPP CXX C ASM)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main
)
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(libcpp STATIC
    CPP/foo.cpp
)
target_include_directories(libcpp PUBLIC CPP)
add_executable(CPP
    CPP/main.cpp
)
target_link_libraries(CPP libcpp)
set_target_properties(CPP PROPERTIES OUTPUT_NAME "cpp")

add_library (libc STATIC
    C/foo.c
)
target_include_directories(libc PUBLIC C)
add_executable(C
    C/main.c
)
target_link_libraries(C libc)
set_target_properties(C PROPERTIES OUTPUT_NAME "c")

enable_testing()
include(GoogleTest)

add_executable(
  HelloWorldTest
  Test/test.cpp
)
target_link_libraries(
  HelloWorldTest
  libcpp
  libc
  GTest::gtest_main
)
gtest_discover_tests(HelloWorldTest)