cmake_minimum_required(VERSION 3.14)

if(NOT ("${FLAME_PLATFORM}" STREQUAL "Posix"))
	return()
endif()

set(NAME "Os.Async.Network.${FLAME_PLATFORM}")
set(NAME_ALIAS "Os::Async::Network::${FLAME_PLATFORM}")
set(INCLUDE_PATHS ${FLAME_INCLUDE_PATH})

set(DEPENDENCY_HEADER_TARGETS ${FLAME_NAMESPACE}::Os::Headers)

get_sources(FILE_LIST)
flame_compile_library(
	NAME "${NAME}"
	SOURCE_LIST "${FILE_LIST}"
	INCLUDE_PATHS "${INCLUDE_PATHS}" "${GENERATED_INCLUDE_PATH}"
	DEPENDENCY_HEADER_TARGETS "${DEPENDENCY_HEADER_TARGETS}"
	OBJECT_ALIAS_NAME
		"${FLAME_NAMESPACE}::${NAME_ALIAS}::Object"
	INDEPENDENT_OBJECT_ALIAS_NAME
		"${FLAME_NAMESPACE}::${NAME_ALIAS}::Object::Independ"

	NO_RTTI
	NO_EXCEPTIONS
)
