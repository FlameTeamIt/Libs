cmake_minimum_required(VERSION 3.14)

set(NAME Bsp.Client)
set(LIBRARY_ALIAS_NAME Bsp::Client::Headers)
# set(DEPENDENCY_LIST)

get_sources(FILE_LIST)
flame_header_library(
	NAME                   "${NAME}"
	LIBRARY_ALIAS_NAME     "${LIBRARY_ALIAS_NAME}"
	HEADER_LIST            "${FILE_LIST}"
	# DEPENDENCY_TARGET_LIST "${DEPENDENCY_LIST}"
	INCLUDE_PATHS          "${FLAME_INCLUDE_PATH}"
	INSTALL_SUBDIR         "${FLAME_NAMESPACE}/${NAME}"
)
add_custom_target("${NAME}" SOURCES ${FILE_LIST})

set(HEADER_MODULES
	${CMAKE_CURRENT_LIST_DIR}/OnBuildLogMessage
	${CMAKE_CURRENT_LIST_DIR}/OnBuildPublishDiagnostics
	${CMAKE_CURRENT_LIST_DIR}/OnBuildShowMessage
	${CMAKE_CURRENT_LIST_DIR}/OnBuildTargetDidChange
	${CMAKE_CURRENT_LIST_DIR}/OnBuildTaskFinish
	${CMAKE_CURRENT_LIST_DIR}/OnBuildTaskProgress
	${CMAKE_CURRENT_LIST_DIR}/OnBuildTaskStart
	${CMAKE_CURRENT_LIST_DIR}/OnRunPrintStdout
)
foreach(module ${HEADER_MODULES})
	add_subdirectory(${module})
endforeach()
