set(FLAME_PLATFORM Posix)

find_library(PTHREAD_LIBRARY pthread)
set(FLAME_LIBRARIES ${PTHREAD_LIBRARY})

function(add_cpp_sources DIR_NAME SOURCE_LIST_VAR)
	execute_process(
		COMMAND find ${DIR_NAME}/ -maxdepth 1 -type f -name "*.cpp"
		OUTPUT_VARIABLE SOURCE_LIST_TEMP
	)
	string(REGEX REPLACE "\n" ";" SOURCE_LIST_TEMP "${SOURCE_LIST_TEMP}")
	set (${SOURCE_LIST_VAR} ${SOURCE_LIST_TEMP} PARENT_SCOPE)
endfunction()

function(add_hpp_sources DIR_NAME SOURCE_LIST_VAR)
	execute_process(
		COMMAND find ${DIR_NAME}/ -type f -name "*.hpp"
		OUTPUT_VARIABLE SOURCE_LIST_TEMP
	)
	string(REGEX REPLACE "\n" ";" SOURCE_LIST_TEMP "${SOURCE_LIST_TEMP}")
	set (${SOURCE_LIST_VAR} ${SOURCE_LIST_TEMP} PARENT_SCOPE)
endfunction()
