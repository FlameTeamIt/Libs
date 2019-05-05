if (UNIX)
	include(cmake/Unix.cmake)
endif (UNIX)
if (WIN32)
	include(cmake/Windows.cmake)
endif (WIN32)


macro(set_object_module
		CURRENT_MODULE_NAME MODULE_WITH_FILES MODULES VARNAME_MODULES)

	set(${VARNAME_MODULES})
	if (${MODULE_WITH_FILES})
		include(Sources.cmake)

		add_library(${CURRENT_MODULE_NAME}
			OBJECT ${SOURCE_LIST})

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
		CURRENT_MODULE_NAME MODULE_WITH_FILES VARNAME_OF_TEST_SUBMODULE)

	set(${VARNAME_OF_TEST_SUBMODULE})

	if (${MODULE_WITH_FILES})
		include(Sources.cmake)

		add_library(${CURRENT_MODULE_NAME} OBJECT ${SOURCE_LIST})

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


function(actualize_header_list
		CURRENT_HEADER_LIST ACTUALIZED_HEADER_LIST)

	set(LOCAL_HEADER_LIST)
	foreach(header ${${CURRENT_HEADER_LIST}})
		string(CONCAT header "../" "${header}")
		list(APPEND LOCAL_HEADER_LIST ${header})
	endforeach()
	set(${ACTUALIZED_HEADER_LIST} ${LOCAL_HEADER_LIST} PARENT_SCOPE)

endfunction(actualize_header_list)
