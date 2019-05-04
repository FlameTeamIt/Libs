set(FLAME_MODULES
    Bus
    Common
    Streams
    Templates
    Threads
    Ubjson
)

foreach(module ${FLAME_MODULES})
    message(${module})

    add_subdirectory(${module})

    if (${module}_MODULES)
        message("\t" "Add ${module}_MODULES")
        set(FLAME_SUBMODULES ${FLAME_SUBMODULES}
            ${${module}_MODULES}
        )
    endif()

    if (${module}_TEST_MODULE)
        message("\t" "Add ${module}_TEST_MODULE")
        set(FLAME_TEST_SUBMODULES ${FLAME_TEST_SUBMODULES}
            ${${module}_TEST_MODULE}
        )
    endif()

endforeach()
add_library(${CMAKE_PROJECT_NAME} ${FLAME_SUBMODULES})

set(FLAME_TEST_SUBMODULES
    ${FLAME_TEST_SUBMODULES}
    ${FLAME_SUBMODULES}
    PARENT_SCOPE
)
