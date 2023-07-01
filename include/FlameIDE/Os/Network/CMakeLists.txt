cmake_minimum_required(VERSION 3.14)

set(NAME Os.Network)
set(LIBRARY_ALIAS_NAME ${FLAME_NAMESPACE}::Os::Network::Headers)
set(DEPENDENCY_LIST
	${FLAME_NAMESPACE}::Os::Headers
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
