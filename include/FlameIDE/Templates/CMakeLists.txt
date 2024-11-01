cmake_minimum_required(VERSION 3.14)

set(NAME Templates)
set(LIBRARY_ALIAS_NAME ${FLAME_NAMESPACE}::Templates::Headers)
set(DEPENDENCY_LIST
	${FLAME_NAMESPACE}::Templates::Allocator::Headers
	${FLAME_NAMESPACE}::Templates::Iterator::Headers
	${FLAME_NAMESPACE}::Templates::Serialization::Headers
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
	${CMAKE_CURRENT_LIST_DIR}/Allocator
	${CMAKE_CURRENT_LIST_DIR}/Iterator
	${CMAKE_CURRENT_LIST_DIR}/Serialization
)
foreach(module ${HEADER_MODULES})
	add_subdirectory(${module})
endforeach()
