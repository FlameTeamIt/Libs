cmake_minimum_required(VERSION 3.14)

set(NAME Constants)
set(LIBRARY_ALIAS_NAME ${FLAME_NAMESPACE}::Constants::Headers)

get_sources(FILE_LIST)
flame_header_library(
	NAME               "${NAME}"
	LIBRARY_ALIAS_NAME "${LIBRARY_ALIAS_NAME}"
	HEADER_LIST        "${FILE_LIST}"
	INCLUDE_PATHS      "${FLAME_INCLUDE_PATH}"
	INSTALL_SUBDIR     "${FLAME_NAMESPACE}/${NAME}"
)
