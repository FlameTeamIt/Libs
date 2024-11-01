cmake_minimum_required(VERSION 3.14)
get_sources(FILE_LIST)

set(NAME "Bus")
set(INCLUDE_PATHS "${FLAME_INCLUDE_PATH}")

set(DEPENDENCY_HEADER_TARGETS "${FLAME_NAMESPACE}::${NAME}::Headers")

if(FLAME_MAKE_STATIC)
	set(MAKE_STATIC MAKE_STATIC)
endif()
if(FLAME_MAKE_SHARED)
	set(MAKE_SHARED MAKE_SHARED)
endif()

flame_compile_library(
	NAME "${NAME}"
	SOURCE_LIST "${FILE_LIST}"
	INCLUDE_PATHS "${INCLUDE_PATHS}"
	DEPENDENCY_HEADER_TARGETS "${DEPENDENCY_HEADER_TARGETS}"
	OBJECT_ALIAS_NAME "${FLAME_NAMESPACE}::${NAME}::Object"
	INDEPENDENT_OBJECT_ALIAS_NAME
		"${FLAME_NAMESPACE}::${NAME}::Object::Independ"
	STATIC_ALIAS_NAME "${FLAME_NAMESPACE}::${NAME}::Static"
	SHARED_ALIAS_NAME "${FLAME_NAMESPACE}::${NAME}::Shared"

	NO_RTTI
	NO_EXCEPTIONS

	${MAKE_SHARED}
	${MAKE_STATIC}
)
