set(FLAME_MODULES
    Analysers
    Bus
    Common
    Streams
    Templates
    Threads
)

set(LOCAL_HEADER_LIST)
actualize_header_list(HEADER_LIST LOCAL_HEADER_LIST)
set(HEADER_LIST ${LOCAL_HEADER_LIST})
unset(LOCAL_HEADER_LIST)

foreach(module ${FLAME_MODULES})
    add_subdirectory(${module})

    message(${module})
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
