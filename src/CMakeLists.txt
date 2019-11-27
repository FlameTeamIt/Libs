cmake_minimum_required(VERSION 3.14)

foreach(module ${SOURCE_MODULES})
	message("Add source module: ${module}")
	add_subdirectory(${module})
endforeach()
