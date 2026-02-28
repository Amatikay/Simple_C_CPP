include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main
)
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_executable(
  HelloWorldTest
  test.cpp
)

target_link_libraries(
  HelloWorldTest
  libcpp
  libc
  GTest::gtest_main
)
gtest_discover_tests(HelloWorldTest)