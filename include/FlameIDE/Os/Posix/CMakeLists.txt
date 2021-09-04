cmake_minimum_required(VERSION 3.14)

if(NOT ("${FLAME_PLATFORM}" STREQUAL "Posix"))
	return()
endif()

set(NAME "Os.${FLAME_PLATFORM}")
set(LIBRARY_ALIAS_NAME ${FLAME_NAMESPACE}::Os::${FLAME_PLATFORM}::Headers)
set(DEPENDENCY_LIST
	${FLAME_NAMESPACE}::Common::Macros::Headers
)

get_sources(FILE_LIST)
flame_header_library(
	NAME                   "${NAME}"
	LIBRARY_ALIAS_NAME     "${LIBRARY_ALIAS_NAME}"
	HEADER_LIST            "${FILE_LIST}"
	DEPENDENCY_TARGET_LIST "${DEPENDENCY_LIST}"
	INCLUDE_PATHS          "${FLAME_INCLUDE_PATH}"
	INSTALL_DIR            "${FLAME_NAMESPACE}/Os/Posix"
)
