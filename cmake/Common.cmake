if (UNIX)
	include(cmake/Unix.cmake)
endif (UNIX)

if (WIN32)
	include(cmake/Windows.cmake)
endif (WIN32)

macro(set_object_module
		CURRENT_MODULE_NAME
		MODULE_WITH_FILES
		MODULES
		VARNAME_MODULES)

	set(${VARNAME_MODULES})
	if (${MODULE_WITH_FILES})
		include(Files.cmake)

		set(OBJECT_LIST ${FILE_LIST})
		add_library(${CURRENT_MODULE_NAME} OBJECT ${OBJECT_LIST})

		set(${VARNAME_MODULES}
			${${VARNAME_MODULES}}
			$<TARGET_OBJECTS:${CURRENT_MODULE_NAME}>
		)
	endif()

	if (MODULES)
		foreach(module ${MODULES})
			add_subdirectory(${module})
			if (${module}_MODULES)
				set(${VARNAME_MODULES}
					${${VARNAME_MODULES}}
					${${module}_MODULES}
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
