add_library(libc
	${CMAKE_CURRENT_SOURCE_DIR}/source/foo.c
)
add_executable(C
	${CMAKE_CURRENT_SOURCE_DIR}/main.c
)
target_include_directories(libc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(C libc)