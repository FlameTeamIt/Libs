cmake_minimum_required(VERSION 3.14)
project(Flame)

set(CMAKE_MAIN_TARGET_NAME ${CMAKE_PROJECT_NAME})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ./cmake)
set(CMAKE_ENABLE_TESTS TRUE)
include(cmake/Common.cmake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(include)
add_subdirectory(src)

add_subdirectory(tests)
