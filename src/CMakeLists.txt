cmake_minimum_required(VERSION 3.14)

set(SOURCE_MODULES
	${FLAME_SOURCE_SUBMODLUES_PATH}/Bus
	${FLAME_SOURCE_SUBMODLUES_PATH}/Streams
	${FLAME_SOURCE_SUBMODLUES_PATH}/Streams/Posix
	${FLAME_SOURCE_SUBMODLUES_PATH}/Streams/Posix/Async
	${FLAME_SOURCE_SUBMODLUES_PATH}/Streams/Windows
	${FLAME_SOURCE_SUBMODLUES_PATH}/Streams/Windows/Async
	${FLAME_SOURCE_SUBMODLUES_PATH}/Threads
	${FLAME_SOURCE_SUBMODLUES_PATH}/Threads/Posix
	${FLAME_SOURCE_SUBMODLUES_PATH}/Threads/Windows
	${FLAME_SOURCE_SUBMODLUES_PATH}/Ubjson
)

foreach(module ${SOURCE_MODULES})
	add_subdirectory(${module})
endforeach()
