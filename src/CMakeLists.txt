cmake_minimum_required(VERSION 3.14)

set(GENERATED_INCLUDE_PATH ${CMAKE_BINARY_DIR}/generated/include)
set(SOURCE_MODULES
	${FLAME_SOURCE_SUBMODLUES_PATH}/Bus
	${FLAME_SOURCE_SUBMODLUES_PATH}/Common
	${FLAME_SOURCE_SUBMODLUES_PATH}/Crypto
	${FLAME_SOURCE_SUBMODLUES_PATH}/Os
	${FLAME_SOURCE_SUBMODLUES_PATH}/Streams
	${FLAME_SOURCE_SUBMODLUES_PATH}/Ubjson
)
foreach(module ${SOURCE_MODULES})
	add_subdirectory(${module})
endforeach()

flame_resolve_targets()
