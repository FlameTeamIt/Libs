cmake_minimum_required(VERSION 3.14)

set(NAME Crypto.Pkcs11.Types.Structs)
set(LIBRARY_ALIAS_NAME ${FLAME_NAMESPACE}::Crypto::Pkcs11::Types::Structs::Headers)
set(DEPENDENCY_LIST
	${FLAME_NAMESPACE}::Crypto::Oasis::Headers
	${FLAME_NAMESPACE}::Common::Traits::Headers
)
get_sources(FILE_LIST)

flame_header_library(
	NAME                   "${NAME}"
	LIBRARY_ALIAS_NAME     "${LIBRARY_ALIAS_NAME}"
	HEADER_LIST            "${FILE_LIST}"
	DEPENDENCY_TARGET_LIST "${DEPENDENCY_LIST}"
	INCLUDE_PATHS          "${FLAME_INCLUDE_PATH}"
)
