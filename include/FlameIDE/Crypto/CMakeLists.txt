cmake_minimum_required(VERSION 3.14)

set(HEADER_MODULES
	${CMAKE_CURRENT_LIST_DIR}/Oasis
	${CMAKE_CURRENT_LIST_DIR}/Pkcs11
)
foreach(module ${HEADER_MODULES})
	add_subdirectory(${module})
endforeach()
