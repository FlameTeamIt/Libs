set(FLAME_MODULES
    Analysers
    Bus
    Common
    Streams
    Templates
    Threads
)

foreach(module ${FLAME_MODULES})
    add_subdirectory(${module})

    message(${module})
    if (${module}_LIST_OF_SUBMODULES)
        set(FLAME_LIST_OF_SUBMODULES ${FLAME_LIST_OF_SUBMODULES}
            ${${module}_LIST_OF_SUBMODULES}
        )
        message("\t"
            "Add ${module}_LIST_OF_SUBMODULES"
        )
    endif()
    if (${module}_TEST_MODULE)
        message("\t"
            "Add ${module}_TEST_MODULE"
        )
        set(FLAME_TEST_MODULES ${FLAME_TEST_MODULES}
            ${${module}_TEST_MODULE}
        )
    endif()

endforeach()
add_library(${CMAKE_PROJECT_NAME} ${FLAME_LIST_OF_SUBMODULES})

set(FLAME_TEST_MODULES
    ${FLAME_TEST_MODULES}
    ${FLAME_LIST_OF_SUBMODULES}
    PARENT_SCOPE
)
