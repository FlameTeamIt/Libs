cmake_minimum_required(VERSION 3.14)

foreach(module ${TEST_MODULES})
	remove_source_dir("${module}" "${FLAME_CURRENT_DIR}/" OUT_DIR)
	add_subdirectory(${module} ${CMAKE_CURRENT_BINARY_DIR}/${OUT_DIR})
endforeach()
