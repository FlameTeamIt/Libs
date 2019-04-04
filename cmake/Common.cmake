if (UNIX)
	include(cmake/Unix.cmake)
endif (UNIX)

if (WIN32)
	include(cmake/Windows.cmake)
endif (WIN32)

macro(set_object_module
		CURRENT_MODULE_NAME
		MODULE_WITH_FILES
		LIST_OF_SUBMODULES
		VARNAME_LIST_OF_SUBMODULES)

	set(${VARNAME_LIST_OF_SUBMODULES})
	if (${MODULE_WITH_FILES})
		include(Files.cmake)

		set(OBJECT_LIST ${FILE_LIST})
		add_library(${CURRENT_MODULE_NAME} OBJECT ${OBJECT_LIST})

		set(${VARNAME_LIST_OF_SUBMODULES}
			${${VARNAME_LIST_OF_SUBMODULES}}
			$<TARGET_OBJECTS:${CURRENT_MODULE_NAME}>
		)
	endif()

	if (LIST_OF_SUBMODULES)
		foreach(module ${LIST_OF_SUBMODULES})
			add_subdirectory(${module})
			if (${module}_LIST_OF_SUBMODULES)
				set(${VARNAME_LIST_OF_SUBMODULES}
					${${VARNAME_LIST_OF_SUBMODULES}}
					${${module}_LIST_OF_SUBMODULES}
				)
			endif()
		endforeach()
	endif()

endmacro(set_object_module)

macro(set_test_module
		CURRENT_MODULE_NAME
		MODULE_WITH_FILES
		VARNAME_OF_TEST_SUBMODULE)

	set(${VARNAME_OF_TEST_SUBMODULE})

	if (${MODULE_WITH_FILES})
		include(Files.cmake)

		set(OBJECT_LIST ${FILE_LIST})
		add_library(${CURRENT_MODULE_NAME} OBJECT ${OBJECT_LIST})

		set(${VARNAME_OF_TEST_SUBMODULE}
			${${VARNAME_OF_TEST_SUBMODULE}}
			$<TARGET_OBJECTS:${CURRENT_MODULE_NAME}>
		)
	endif()
endmacro(set_test_module)

macro(add_tests
		ENABLE_TESTS)
	if(ENABLE_TESTS)
		add_subdirectory(Tests)
	endif()
endmacro(add_tests)
