cmake_minimum_required(VERSION 3.14)
project(Flame)

include(cmake/Common.cmake)

set(DIR_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(DIR_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(DIR_TESTS ${CMAKE_CURRENT_SOURCE_DIR}/tests)

set(FLAMEIDE_LIB_SOURCE_LIST)
set(FLAMEIDE_LIB_TESTS_SOURCE_LIST)

add_subdirectory(${DIR_SOURCE})
add_subdirectory(${DIR_INCLUDE})

include_directories(${DIR_INCLUDE})
add_library(Flame ${FLAMEIDE_LIB_SOURCE_LIST})

# tests

add_subdirectory(${DIR_TESTS})
add_executable(FlameTests ${FLAMEIDE_LIB_TESTS_SOURCE_LIST})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(FlameTests Flame pthread)
