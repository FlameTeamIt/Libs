cmake_minimum_required(VERSION 3.14)

foreach(module ${TEST_MODULES})
	add_subdirectory(${module} tests/${module})
endforeach()
