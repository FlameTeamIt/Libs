cmake_minimum_required(VERSION 3.14)

set(NAME Bsp.Server)
set(LIBRARY_ALIAS_NAME Bsp::Server::Headers)
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
	${CMAKE_CURRENT_LIST_DIR}/BuildInitialize
	${CMAKE_CURRENT_LIST_DIR}/BuildTargetCleanCache
	${CMAKE_CURRENT_LIST_DIR}/BuildTargetCompile
	${CMAKE_CURRENT_LIST_DIR}/BuildTargetDependencyModules
	${CMAKE_CURRENT_LIST_DIR}/BuildTargetDependencySources
	${CMAKE_CURRENT_LIST_DIR}/BuildTargetInverseSources
	${CMAKE_CURRENT_LIST_DIR}/BuildTargetOutputPaths
	${CMAKE_CURRENT_LIST_DIR}/BuildTargetResources
	${CMAKE_CURRENT_LIST_DIR}/BuildTargetRun
	${CMAKE_CURRENT_LIST_DIR}/BuildTargetSources
	${CMAKE_CURRENT_LIST_DIR}/BuildTargetTest
	${CMAKE_CURRENT_LIST_DIR}/DebugSessionStart
	${CMAKE_CURRENT_LIST_DIR}/OnRunReadStdin
	${CMAKE_CURRENT_LIST_DIR}/WorkspaceBuildTargets
)
foreach(module ${HEADER_MODULES})
	add_subdirectory(${module})
endforeach()
