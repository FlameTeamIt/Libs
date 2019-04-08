set(NAME Analysers)

set(MODULE_WITH_FILES FALSE)
set(MODULES Ubjson)
set_object_module(
    ${NAME}
    ${MODULE_WITH_FILES}
    ${MODULES}
    LIST_OF_MODULES
)

set(${NAME}_MODULES
    ${LIST_OF_MODULES}
    PARENT_SCOPE
)

add_tests(FALSE)
