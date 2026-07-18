add_library(libcpp
	${CMAKE_CURRENT_SOURCE_DIR}/cource/foo.cpp
)

add_executable(CPP
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_include_directories(libcpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(CPP libcpp)