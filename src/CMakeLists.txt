cmake_minimum_required(VERSION 3.14)

foreach(module ${SOURCE_MODULES})
	if(FLAME_CMAKE_DEBUG)
		message("Add source module: ${module}")
	endif()
	add_subdirectory(${module})
endforeach()
