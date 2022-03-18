#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_GENERALPURPOSEFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_GENERALPURPOSEFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief Initializes the Cryptoki library
/// @param[in] pInitArgs if this is not NULL_PTR, it gets cast to
/// CK_C_INITIALIZE_ARGS_PTR and dereferenced
/// @return See CKR_* values
///
CK_RV C_Initialize(CK_VOID_PTR pInitArgs);

///
/// @brief Indicates that an application is done with the Cryptoki library
/// @param pReserved reserved; should be NULL_PTR
/// @return See CKR_* values
///
CK_RV C_Finalize(CK_VOID_PTR pReserved);

///
/// @brief Returns general information about Cryptoki
/// @param[out] pInfo Location that receives information
/// @return See CKR_* values
///
CK_RV C_GetInfo(CK_INFO_PTR pInfo);

///
/// @brief Returns the function list
/// @param ppFunctionList receives pointer to function list
/// @return See CKR_* values
///
CK_RV C_GetFunctionList(CK_FUNCTION_LIST_PTR_PTR ppFunctionList);

// v3.0

///
/// @brief Returns all the interfaces supported by the module
/// @param pInterfacesList Returned interfaces
/// @param pulCount Number of interfaces returned
/// @return See CKR_* values
///
CK_RV C_GetInterfaceList(CK_INTERFACE_PTR pInterfacesList, CK_ULONG_PTR pulCount);

///
/// @brief Returns a specific interface from the module
/// @param pInterfaceName Name of the interface
/// @param pVersion Version of the interface
/// @param ppInterface Returned interface
/// @param flags Flags controlling the semantics of the interface
/// @return See CKR_* values
///
CK_RV C_GetInterface(CK_UTF8CHAR_PTR pInterfaceName, CK_VERSION_PTR pVersion,
		CK_INTERFACE_PTR_PTR ppInterface, CK_FLAGS flags);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_GENERALPURPOSEFUNCTIONS_HPP
