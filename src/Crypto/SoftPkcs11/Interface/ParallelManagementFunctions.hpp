#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_PARALLELMANAGEMENTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_PARALLELMANAGEMENTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief Legacy function; it obtains an updated status of a function running in
/// parallel with an application
/// @param[in] hSession The session's handle
/// @return See CKR_* values
///
CK_RV C_GetFunctionStatus(CK_SESSION_HANDLE hSession);

///
/// @brief Legacy function; it cancels a function running in parallel
/// @param[in] hSession The session's handle
/// @return See CKR_* values
///
CK_RV C_CancelFunction(CK_SESSION_HANDLE hSession);

///
/// @brief Wait for a slot event (token insertion, removal, etc.) to occur
/// @param[in] flags Blocking/nonblocking flag
/// @param[out] pSlot Location that receives the slot ID
/// @param[in] pReserved Reserved. Should be NULL_PTR
/// @return See CKR_* values
///
CK_RV C_WaitForSlotEvent(CK_FLAGS flags, CK_SLOT_ID_PTR pSlot, CK_VOID_PTR pReserved);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_PARALLELMANAGEMENTFUNCTIONS_HPP
