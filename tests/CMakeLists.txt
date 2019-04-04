include(Files.cmake)
add_executable(FlameRunnableTests ${FILE_LIST} ${FLAME_TEST_MODULES})
target_link_libraries(FlameRunnableTests ${FLAME_LIBRARIES})
