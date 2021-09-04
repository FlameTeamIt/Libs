cmake_minimum_required(VERSION 3.14)

set(NAME Common)
set(LIBRARY_ALIAS_NAME ${FLAME_NAMESPACE}::Common::Headers)
set(DEPENDENCY_LIST
	${FLAME_NAMESPACE}::Common::Macros::Headers
	${FLAME_NAMESPACE}::Common::Traits::Headers
)

get_sources(FILE_LIST)
flame_header_library(
	NAME                   "${NAME}"
	LIBRARY_ALIAS_NAME     "${LIBRARY_ALIAS_NAME}"
	HEADER_LIST            "${FILE_LIST}"
	DEPENDENCY_TARGET_LIST "${DEPENDENCY_LIST}"
	INCLUDE_PATHS          "${FLAME_INCLUDE_PATH}"
	INSTALL_DIR            "${FLAME_NAMESPACE}/${NAME}"
)

set(HEADER_MODULES
	${CMAKE_CURRENT_LIST_DIR}/Macros
	${CMAKE_CURRENT_LIST_DIR}/Traits
)
foreach(module ${HEADER_MODULES})
	add_subdirectory(${module})
endforeach()
