cmake_minimum_required(VERSION 3.14)

set(NAME "Os")
set(LIBRARY_ALIAS_NAME ${FLAME_NAMESPACE}::Os::Headers)
set(DEPENDENCY_LIST
	${FLAME_NAMESPACE}::Common::Macros::Headers
	${FLAME_NAMESPACE}::${NAME}::${FLAME_PLATFORM}::Headers
	${FLAME_NAMESPACE}::${NAME}::Threads::Headers
	${FLAME_NAMESPACE}::${NAME}::Network::Headers
	${FLAME_NAMESPACE}::${NAME}::Async::Network::Headers
)

get_sources(FILE_LIST)
flame_header_library(
	NAME                   "${NAME}"
	LIBRARY_ALIAS_NAME     "${LIBRARY_ALIAS_NAME}"
	HEADER_LIST            "${FILE_LIST}"
	DEPENDENCY_TARGET_LIST "${DEPENDENCY_LIST}"
	INCLUDE_PATHS          "${FLAME_INCLUDE_PATH}"
	INSTALL_SUBDIR         "${FLAME_NAMESPACE}/${NAME}"
)

set(HEADER_MODULES
	${CMAKE_CURRENT_LIST_DIR}/Posix
	${CMAKE_CURRENT_LIST_DIR}/Windows
	${CMAKE_CURRENT_LIST_DIR}/Threads
	${CMAKE_CURRENT_LIST_DIR}/Network
	${CMAKE_CURRENT_LIST_DIR}/Async
)
foreach(module ${HEADER_MODULES})
	add_subdirectory(${module})
endforeach()
