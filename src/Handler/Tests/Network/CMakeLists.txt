cmake_minimum_required(VERSION 3.14)

if(NOT FLAME_TESTING)
	return()
endif()

set(NAME "Handler.Network.Test")
set(NAME_ALIAS "Handler::Network::Test")

get_sources(FILE_LIST)

set(DEPENDENCY_HEADER_TARGETS
	"${FLAME_NAMESPACE}::Handler::Network::Headers"
)

flame_compile_library(
	NAME "${NAME}"
	SOURCE_LIST "${FILE_LIST}"
	INCLUDE_PATHS "${INCLUDE_PATHS}" "${CMAKE_BINARY_DIR}/generated/include"
	DEPENDENCY_HEADER_TARGETS "${DEPENDENCY_HEADER_TARGETS}"

	OBJECT_ALIAS_NAME
		"${FLAME_NAMESPACE}::${NAME_ALIAS}::Object"
	INDEPENDENT_OBJECT_ALIAS_NAME
		"${FLAME_NAMESPACE}::${NAME_ALIAS}::Object::Independ"

	NO_RTTI
	EXCEPTIONS
)
