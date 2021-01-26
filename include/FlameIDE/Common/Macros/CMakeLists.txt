cmake_minimum_required(VERSION 3.14)

set(NAME "Common.Macros")
set(LIBRARY_ALIAS_NAME ${FLAME_NAMESPACE}::Common::Macros::Headers)
get_sources(FILE_LIST)

flame_header_library(
	NAME               "${NAME}"
	LIBRARY_ALIAS_NAME "${LIBRARY_ALIAS_NAME}"
	HEADER_LIST        "${FILE_LIST}"
	INCLUDE_PATHS      "${FLAME_INCLUDE_PATH}"
)
