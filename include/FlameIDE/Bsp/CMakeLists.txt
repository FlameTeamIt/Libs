cmake_minimum_required(VERSION 3.14)

set(NAME Bsp)
set(LIBRARY_ALIAS_NAME Bsp::Headers)
# set(DEPENDENCY_LIST)

# get_sources(FILE_LIST)
# flame_header_library(
# 	NAME                   "${NAME}"
# 	LIBRARY_ALIAS_NAME     "${LIBRARY_ALIAS_NAME}"
# 	HEADER_LIST            "${FILE_LIST}"
# 	DEPENDENCY_TARGET_LIST "${DEPENDENCY_LIST}"
# 	INCLUDE_PATHS          "${FLAME_INCLUDE_PATH}"
# 	INSTALL_SUBDIR         "${FLAME_NAMESPACE}/${NAME}"
# )

set(HEADER_MODULES
	${CMAKE_CURRENT_LIST_DIR}/Common
	${CMAKE_CURRENT_LIST_DIR}/Server
	${CMAKE_CURRENT_LIST_DIR}/Client
)
foreach(module ${HEADER_MODULES})
	add_subdirectory(${module})
endforeach()
