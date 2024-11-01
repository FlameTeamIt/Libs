cmake_minimum_required(VERSION 3.14)

set(NAME "SoftPkcs11")
set(SUBALIAS_NAME "Crypto::SoftPkcs11")
set(INCLUDE_PATHS ${FLAME_INCLUDE_PATH})

set(DEPENDENCY_HEADER_TARGETS
	"${FLAME_NAMESPACE}::Crypto::Oasis::Headers"
	"${FLAME_NAMESPACE}::Crypto::Pkcs11::Types::Headers"
)
set(DEPENDENCY_TARGETS_FOR_SHARED
	"${FLAME_NAMESPACE}::${SUBALIAS_NAME}::Functions::Object::Independ"
	"${FLAME_NAMESPACE}::${SUBALIAS_NAME}::Interface::Object::Independ"
#	"${FLAME_NAMESPACE}::${SUBALIAS_NAME}::Mechanisms::Object::Independ"
	"${FLAME_NAMESPACE}::${SUBALIAS_NAME}::Mechanisms::Base::Object::Independ"
	"${FLAME_NAMESPACE}::Crypto::Pkcs11::MutexStub::Object::Independ"
	"${FLAME_NAMESPACE}::Crypto::Pkcs11::Types::Structs::Object::Independ"
)
if(FLAME_MAKE_SHARED)
	set(MAKE_SHARED MAKE_SHARED)
endif()

get_sources(FILE_LIST)
flame_compile_library(
	NAME "${NAME}"
	SOURCE_LIST "${FILE_LIST}"
	INCLUDE_PATHS "${INCLUDE_PATHS}"
	DEPENDENCY_HEADER_TARGETS     "${DEPENDENCY_HEADER_TARGETS}"
	DEPENDENCY_TARGETS_FOR_SHARED "${DEPENDENCY_TARGETS_FOR_SHARED}"
	OBJECT_ALIAS_NAME "${FLAME_NAMESPACE}::${SUBALIAS_NAME}::Object"
	INDEPENDENT_OBJECT_ALIAS_NAME
		"${FLAME_NAMESPACE}::${SUBALIAS_NAME}::Object::Independ"
	SHARED_ALIAS_NAME "${FLAME_NAMESPACE}::${SUBALIAS_NAME}::Shared"

	NO_RTTI
	NO_EXCEPTIONS

	${MAKE_SHARED}
)

set(SOURCE_MODULES
	${CMAKE_CURRENT_LIST_DIR}/Functions
	${CMAKE_CURRENT_LIST_DIR}/Interface
	${CMAKE_CURRENT_LIST_DIR}/Mechanisms
)
foreach(module ${SOURCE_MODULES})
	add_subdirectory(${module})
endforeach()
