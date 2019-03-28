if (UNIX)
	include(cmake/Unix.cmake)
endif (UNIX)

if (WIN32)
	include(cmake/Windows.cmake)
endif (WIN32)
