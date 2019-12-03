cmake_minimum_required(VERSION 3.14)

foreach(module ${TEST_MODULES})
	remove_source_dir("${module}" "${FLAME_CURRENT_DIR}/src/" OUT_DIR)
	remove_source_dir("${OUT_DIR}" "/Tests" OUT_DIR)
	message("OUT_DIR = ${OUT_DIR}")
	add_subdirectory(${module} ${CMAKE_CURRENT_BINARY_DIR}/${OUT_DIR})
endforeach()
