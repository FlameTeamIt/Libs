cmake_minimum_required(VERSION 3.14)

foreach(module ${HEADER_MODULES})
	message("Add header module: ${module}")
	add_subdirectory(${module})
endforeach()
