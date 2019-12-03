cmake_minimum_required(VERSION 3.14)

foreach(module ${HEADER_MODULES})
	if(FLAME_CMAKE_DEBUG)
		message("Add header module: ${module}")
	endif()
	add_subdirectory(${module})
endforeach()
