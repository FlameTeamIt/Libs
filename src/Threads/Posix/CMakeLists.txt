set(NAME Posix)

set(MODULE_WITH_FILES TRUE)
set(MODULES FALSE)

set_object_module(
    PosixThreads
    ${MODULE_WITH_FILES}
    ${MODULES}
    LIST_OF_MODULES)

set(${NAME}_MODULES ${LIST_OF_MODULES} PARENT_SCOPE)
