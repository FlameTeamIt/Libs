cmake_minimum_required(VERSION 3.14)

set(HEADER_MODULES
	${CMAKE_CURRENT_LIST_DIR}/Network
)
foreach(module ${HEADER_MODULES})
	add_subdirectory(${module})
endforeach()
