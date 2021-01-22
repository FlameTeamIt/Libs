cmake_minimum_required(VERSION 3.14)

function(remove_source_dir PATH REMOVE_PATH OUT)
	string(REPLACE "${REMOVE_PATH}" "" ${OUT} "${PATH}")
	set(${OUT} "${${OUT}}" PARENT_SCOPE)
endfunction(remove_source_dir)

set(TEST_MODULES
	${FLAME_SOURCE_SUBMODLUES_PATH}/Templates/Tests
	${FLAME_SOURCE_SUBMODLUES_PATH}/Streams/Tests
	${FLAME_SOURCE_SUBMODLUES_PATH}/Threads/Tests
	${FLAME_SOURCE_SUBMODLUES_PATH}/Common/Tests
)

foreach(module ${TEST_MODULES})
	remove_source_dir("${module}" "${FLAME_SOURCE_SUBMODLUES_PATH}/" OUT_DIR)
	remove_source_dir("${OUT_DIR}" "/Tests" OUT_DIR)
	add_subdirectory(${module} ${CMAKE_CURRENT_BINARY_DIR}/${OUT_DIR})
endforeach()

set(NAME "Tests")
set(ALIAS_NAME "Flame::Tests")
get_sources(FILE_LIST)

set(INCLUDE_PATHS
	${FLAME_INCLUDE_PATH}
	${FLAME_INCLUDE_TEST_PATH}
)

set(DEPENDENCY_TARGET_LIST
	"${FLAME_NAMESPACE}::Templates::Tests::Static"
	"${FLAME_NAMESPACE}::Streams::Tests::Static"
	"${FLAME_NAMESPACE}::Threads::Tests::Static"
	"${FLAME_NAMESPACE}::Common::Tests::Static"
)

flame_compile_binary(
	NAME "${NAME}"
	ALIAS_NAME "${ALIAS_NAME}"
	SOURCE_LIST "${FILE_LIST}"
	#INSTALL_PATH
	INCLUDE_PATHS "${INCLUDE_PATHS}"
	#HEADER_LIST
	#COMMPILE_FLAGS"
	#LINK_FLAGS"
	DEPENDENCY_TARGET_LIST "${DEPENDENCY_TARGET_LIST}"
)
