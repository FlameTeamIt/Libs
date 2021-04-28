cmake_minimum_required(VERSION 3.14)

find_package(Git REQUIRED)
if(NOT Git_FOUND)
	message(FATAL_ERROR "Git not found.")
endif()

function(download_resolver)
	set(RESOLVER_NAME CMakeFlameResolver)
	set(RESOLVER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${RESOLVER_NAME})
	set(RESOLVER_URL "https://github.com/kachsheev/${RESOLVER_NAME}.git")
	set(RESOLVER_VERSION "master")
	if(NOT (EXISTS "${RESOLVER_PATH}" AND IS_DIRECTORY "${RESOLVER_PATH}"))
		execute_process(
			COMMAND
				${GIT_EXECUTABLE} clone ${RESOLVER_URL} --branch ${RESOLVER_VERSION}
				${RESOLVER_PATH}
		)
	else()
		message(STATUS "Not need to clone '${RESOLVER_NAME} ${RESOLVER_VERSION}'")
	endif()
	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${RESOLVER_PATH}/cmake" PARENT_SCOPE)
	set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "${RESOLVER_PATH}")
endfunction()

download_resolver()
