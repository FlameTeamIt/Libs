cmake_minimum_required(VERSION 3.14)

if(FLAME_TESTING)
	set(NAME "Streams.Tests")
	set(NAME_ALIAS "Streams::Tests")
	set(INCLUDE_PATHS
		${FLAME_INCLUDE_PATH}
		${FLAME_INCLUDE_TEST_PATH}
	)
	get_sources(FILE_LIST)

	set(DEPENDENCY_HEADER_TARGETS "${FLAME_NAMESPACE}::Streams::Headers")
	set(DEPENDENCY_TARGETS_FOR_STATIC "${FLAME_NAMESPACE}::Streams::Static")
	set(DEPENDENCY_TARGETS_FOR_SHARED "${FLAME_NAMESPACE}::Streams::Shared")

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
		DEPENDENCY_HEADER_TARGETS     "${DEPENDENCY_HEADER_TARGETS}"
		DEPENDENCY_TARGETS_FOR_STATIC "${DEPENDENCY_TARGETS_FOR_STATIC}"
		DEPENDENCY_TARGETS_FOR_SHARED "${DEPENDENCY_TARGETS_FOR_SHARED}"
		OBJECT_ALIAS_NAME "${FLAME_NAMESPACE}::${NAME_ALIAS}::Object"
		INDEPENDENT_OBJECT_ALIAS_NAME
			"${FLAME_NAMESPACE}::${NAME_ALIAS}::Object::Independ"
		STATIC_ALIAS_NAME "${FLAME_NAMESPACE}::${NAME_ALIAS}::Static"
		SHARED_ALIAS_NAME "${FLAME_NAMESPACE}::${NAME_ALIAS}::Shared"
		${MAKE_STATIC}
		${MAKE_SHARED}
	)
endif()
