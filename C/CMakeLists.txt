add_library (libc STATIC
    foo.c
)
add_executable(C
    main.c
)
target_include_directories(libc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
target_link_libraries(C libc)