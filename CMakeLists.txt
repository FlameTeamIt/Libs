cmake_minimum_required(VERSION 3.14)

project(Flame LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MAIN_TARGET_NAME ${CMAKE_PROJECT_NAME})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(FLAME_NAMESPACE "FlameIDE")
set(FLAME_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(FLAME_INCLUDE_TEST_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(FLAME_CURRENT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(FLAME_ROOT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/src)

set(FLAME_INCLUDE_SUBMODLUES_PATH ${FLAME_INCLUDE_PATH}/FlameIDE)
set(FLAME_SOURCE_SUBMODLUES_PATH ${FLAME_CURRENT_DIR}/src)
set(FLAME_TEST_SUBMODLUES_PATH ${FLAME_CURRENT_DIR}/tests)

include(FlameContrib)
include(CmakeFlameResolver)
flame_resolver_settings(
	# Common options
	#	CMAKE_DEBUG                    # OFF
	#	CMAKE_DEBUG_SHOW_PARSE_RESULTS # OFF
	#	PRINT_COMMON_STATISTIC         # OFF
	#	PRINT_DETAILED_STATISTIC       # OFF
	LOGGING                        # ON
	CLEAN_AFTER_RESOLVE            # ON
	THREADING                      # ON
	TESTING                        # ON
	INSTALL                        # ON
	LOCAL_INSTALL                  # ON
	CMAKE_PACKAGING                # ON
	INPLACE_OBJECTS                # ON
	SHOW_HEADERS                   # ON

	# Code generation options
	ONLY_POSITION_INDEPENDENT_OBJECTS # ON
	MAKE_STATIC                       # ON
	MAKE_SHARED                       # ON
	#	MAKE_STANDALONE               # OFF
	EXPORT_ALL_SYMBOLS                # ON

	# Flag options
	#	CXX_NO_RTTI       # OFF
	#	CXX_NO_EXCEPTIONS # OFF
	PLATFORM_DEFINES   # ON
	WARNINGS           # ON
	#	WARNINGS_AS_ERRORS # OFF

	# Values
	PROJECT_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}
	LOCAL_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install
)
if(FLAME_TESTING)
	message(STATUS "Tests enabled")
	enable_testing()
endif()

add_subdirectory(${FLAME_INCLUDE_SUBMODLUES_PATH})
add_subdirectory(${FLAME_SOURCE_SUBMODLUES_PATH})
add_subdirectory(${FLAME_TEST_SUBMODLUES_PATH})
