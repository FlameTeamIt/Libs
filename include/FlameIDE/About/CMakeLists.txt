cmake_minimum_required(VERSION 3.14)

set(NAME About)
set(LIBRARY_ALIAS_NAME ${FLAME_NAMESPACE}::About::Headers)

get_sources(FILE_LIST)
flame_header_library(
	NAME               "${NAME}"
	HEADER_LIST        "${FILE_LIST}"
	LIBRARY_ALIAS_NAME "${LIBRARY_ALIAS_NAME}"
	INCLUDE_PATHS      "${FLAME_INCLUDE_PATH}"
	INSTALL_SUBDIR     "${FLAME_NAMESPACE}/${NAME}"
)
