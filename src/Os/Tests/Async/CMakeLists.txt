cmake_minimum_required(VERSION 3.14)

if(NOT FLAME_TESTING)
	return()
endif()

set(SOURCE_MODULES
	${CMAKE_CURRENT_LIST_DIR}/Network
)
foreach(module ${SOURCE_MODULES})
	add_subdirectory(${module})
endforeach()
