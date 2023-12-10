cmake_minimum_required(VERSION 3.14)

set(NAME Json)
set(NAME_ALIAS "${NAME}")
set(INCLUDE_PATHS ${FLAME_INCLUDE_PATH})

# get_sources(FILE_LIST)
# flame_compile_library(
# 	...
# )

set(SOURCE_MODULES
	${CMAKE_CURRENT_LIST_DIR}/StateMachines
)
foreach(module ${SOURCE_MODULES})
	add_subdirectory(${module})
endforeach()
