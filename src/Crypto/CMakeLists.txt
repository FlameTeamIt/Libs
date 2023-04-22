cmake_minimum_required(VERSION 3.14)

set(SOURCE_MODULES
	${CMAKE_CURRENT_LIST_DIR}/Pkcs11
	${CMAKE_CURRENT_LIST_DIR}/SoftPkcs11
)
foreach(module ${SOURCE_MODULES})
	add_subdirectory(${module})
endforeach()
