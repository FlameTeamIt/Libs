cmake_minimum_required(VERSION 3.14)
project(Flame)

set(CMAKE_MAIN_TARGET_NAME ${CMAKE_PROJECT_NAME})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ./cmake)
set(CMAKE_ENABLE_TESTS TRUE)

set(FLAME_TEST_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(FLAME_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(FLAME_INCLUDE_SUBMODLUES_PATH ${FLAME_INCLUDE_PATH}/FlameIDE)

include(cmake/Common.cmake)

include_directories(${FLAME_INCLUDE_PATH} ${FLAME_TEST_PATH})
add_subdirectory(src)

add_subdirectory(tests)
