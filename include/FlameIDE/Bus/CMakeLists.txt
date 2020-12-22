cmake_minimum_required(VERSION 3.14)

set(NAME Bus)
set(LIBRARY_ALIAS_NAME ${FLAME_NAMESPACE}::Bus::Headers)
set(DEPENDENCY_LIST
	${FLAME_NAMESPACE}::Templates::Headers
)
get_sources(FILE_LIST)

flame_header_library(
	NAME                   "${NAME}"
	HEADER_LIST            "${FILE_LIST}"
	INCLUDE_PATHS          "${FLAME_INCLUDE_PATH}"
	DEPENDENCY_TARGET_LIST "${DEPENDENCY_LIST}"
	LIBRARY_ALIAS_NAME     "${LIBRARY_ALIAS_NAME}"
)
