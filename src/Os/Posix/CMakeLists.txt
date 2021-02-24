if("${FLAME_PLATFORM}" STREQUAL "Posix")
	set(NAME "Os.${FLAME_PLATFORM}")
	set(NAME_ALIAS "Os::${FLAME_PLATFORM}")
	set(INCLUDE_PATHS ${FLAME_INCLUDE_PATH})
	get_sources(FILE_LIST)

	set(DEPENDENCY_HEADER_TARGETS ${FLAME_NAMESPACE}::Os::Headers)
	find_static_library(dl dl.static)
	find_shared_library(dl dl.shared)

	flame_compile_library(
		NAME "${NAME}"
		SOURCE_LIST "${FILE_LIST}"
		INCLUDE_PATHS "${INCLUDE_PATHS}"
		DEPENDENCY_HEADER_TARGETS "${DEPENDENCY_HEADER_TARGETS}"
		OBJECT_ALIAS_NAME
			"${FLAME_NAMESPACE}::${NAME_ALIAS}::Object"
		INDEPENDENT_OBJECT_ALIAS_NAME
			"${FLAME_NAMESPACE}::${NAME_ALIAS}::Object::Independ"
	)
endif()
