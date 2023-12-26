cmake_minimum_required(VERSION 3.14)

set(NAME Bsp.Server.BuildTargetResources)
set(LIBRARY_ALIAS_NAME Bsp::Server::BuildTargetResources::Headers)
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
