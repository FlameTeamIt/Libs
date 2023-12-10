cmake_minimum_required(VERSION 3.14)

set(NAME "Json.StateMachines")
set(NAME_ALIAS "Json::StateMachines")
set(INCLUDE_PATHS ${FLAME_INCLUDE_PATH})

get_sources(FILE_LIST)
flame_compile_library(
	NAME "${NAME}"
	SOURCE_LIST "${FILE_LIST}"
	INCLUDE_PATHS "${INCLUDE_PATHS}"
	OBJECT_ALIAS_NAME
		"${FLAME_NAMESPACE}::${NAME_ALIAS}::Object"
	INDEPENDENT_OBJECT_ALIAS_NAME
		"${FLAME_NAMESPACE}::${NAME_ALIAS}::Object::Independ"

	NO_RTTI
	NO_EXCEPTIONS
)
