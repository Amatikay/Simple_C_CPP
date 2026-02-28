add_library(libcpp STATIC
    foo.cpp
)
add_executable(CPP
    main.cpp
)
target_include_directories(libcpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

target_link_libraries(CPP libcpp)