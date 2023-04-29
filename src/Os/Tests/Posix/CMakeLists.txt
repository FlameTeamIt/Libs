cmake_minimum_required(VERSION 3.14)

if(NOT ("${FLAME_PLATFORM}" STREQUAL "Posix"))
	return()
endif()

set(PREFIX "Os.Tests.Posix")
set(PREFIX_ALIAS "Os::Tests::Posix")

set(NAMES
	"UdpServer"
	"UdpClient"
)

set(DEPENDENCY_TARGETS_FOR_STATIC
	"${FLAME_NAMESPACE}::Os::Static"
	"${FLAME_NAMESPACE}::Threads::Static"
)

foreach(name ${NAMES})
	flame_compile_binary(
		NAME "${PREFIX}.${name}"
		SOURCE_LIST "${CMAKE_CURRENT_SOURCE_DIR}/${name}.cpp"
		#INSTALL_PATH
		INCLUDE_PATHS "${FLAME_INCLUDE_PATH}"
		#HEADER_LIST
		#COMMPILE_FLAGS
		#LINK_FLAGS"
		DEPENDENCY_TARGET_LIST "${DEPENDENCY_TARGETS_FOR_STATIC}"

		NO_RTTI
		NO_EXCEPTIONS
	)
endforeach()
