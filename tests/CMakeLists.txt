include(Sources.cmake)
message("FLAME_TEST_SUBMODULES = \n\t${FLAME_TEST_SUBMODULES}")
add_executable(FlameRunnableTests ${SOURCE_LIST} ${FLAME_TEST_SUBMODULES})
target_link_libraries(FlameRunnableTests ${FLAME_LIBRARIES})
