cmake_minimum_required(VERSION 3.14)

set(NAME Templates)
set(LIBRARY_ALIAS_NAME ${FLAME_NAMESPACE}::Templates::Headers)
set(DEPENDENCY_LIST
	${FLAME_NAMESPACE}::Templates::Allocator::Headers
	${FLAME_NAMESPACE}::Templates::Iterator::Headers
	${FLAME_NAMESPACE}::Templates::Serialization::Headers
)
set(HEADER_LIST_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Headers.cmake)

header_library(
	LIBRARY_NAME       "${NAME}"
	LIBRARY_ALIAS_NAME "${LIBRARY_ALIAS_NAME}"
	HEADER_LIST_FILE   "${HEADER_LIST_FILE}"
	DEPENDENCY_LIST    "${DEPENDENCY_LIST}"
	INCLUDE_PATH       "${FLAME_INCLUDE_PATH}"

	${FLAME_CMAKE_DEBUG}
)
