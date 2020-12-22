cmake_minimum_required(VERSION 3.14)

if(${FLAME_ENABLE_ASYNC})
	set(NAME "Streams${FLAME_NAME_SEPARATOR}Async")
	get_sources(FILE_LIST)
	set(LIBRARY_ALIAS_NAME ${FLAME_NAMESPACE}::Streams::Async::Headers)
	set(DEPENDENCY_LIST
		${FLAME_NAMESPACE}::Common::Headers
		${FLAME_NAMESPACE}::Templates::Headers
	)

	header_library(
		NAME               "${NAME}"
		LIBRARY_ALIAS_NAME "${LIBRARY_ALIAS_NAME}"
		HEADER_LIST        "${FILE_LIST}"
		DEPENDENCY_LIST    "${DEPENDENCY_LIST}"
		INCLUDE_PATHS      "${FLAME_INCLUDE_PATH}"
	)
endif()
