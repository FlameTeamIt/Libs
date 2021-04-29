cmake_minimum_required(VERSION 3.14)

project(Flame)

# TODO
# Надо подумать надо Muticonfig-ом
# Есть проблема с тем, что могут внешние библиотеки линковаться
# Как вариант обхода этого -- ввести external-линкующиеся библиотеки, и на них делать алиасы с типом сборки

#	if ("${CMAKE_BUILD_TYPE}" STREQUAL "Multi")
#		set(FLAME_BUILD_TYPES "Debug" "Release" "RelWithDebInfo" "MinSizeRel")
#		foreach(BUILD_TYPE ${FLAME_BUILD_TYPES})
#			set(CMAKE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${BUILD_TYPE})
#			file(MAKE_DIRECTORY ${CMAKE_OUTPUT_DIRECTORY})
#		endif()
#	else()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MAIN_TARGET_NAME ${CMAKE_PROJECT_NAME})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(FLAME_NAMESPACE ${PROJECT_NAME})
set(FLAME_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(FLAME_INCLUDE_TEST_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(FLAME_CURRENT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(FLAME_ROOT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

set(FLAME_INCLUDE_SUBMODLUES_PATH ${FLAME_INCLUDE_PATH}/FlameIDE)
set(FLAME_SOURCE_SUBMODLUES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(FLAME_TEST_SUBMODLUES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/tests)

include(FlameContrib)
include(CmakeFlameResolver)
enable_testing()

set(FLAME_PLATFORM_DEFINES ON)

function(get_sources OUTPUT_NAME)
	set(SOURCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Sources.cmake")
	if(EXISTS ${SOURCE_FILE})
		include(${SOURCE_FILE})
		list(APPEND FILE_LIST ${SOURCE_LIST})
		unset(SOURCE_LIST)
	endif()

	set(HEADER_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Headers.cmake")
	if(EXISTS ${HEADER_FILE})
		include(${HEADER_FILE})
		list(APPEND FILE_LIST ${HEADER_LIST})
		unset(HEADER_LIST)
	endif()

	set(${OUTPUT_NAME} ${FILE_LIST} PARENT_SCOPE)
endfunction()

add_subdirectory(${FLAME_INCLUDE_SUBMODLUES_PATH})
add_subdirectory(${FLAME_SOURCE_SUBMODLUES_PATH})
add_subdirectory(${FLAME_TEST_SUBMODLUES_PATH})

flame_resolve_targets()
