#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_PARALLELMANAGEMENTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_PARALLELMANAGEMENTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief C_GetFunctionStatus
/// @param hSession
/// @return
///
CK_RV C_GetFunctionStatus(CK_SESSION_HANDLE hSession);

///
/// @brief C_CancelFunction
/// @param hSession
/// @return
///
CK_RV C_CancelFunction(CK_SESSION_HANDLE hSession);

///
/// @brief C_WaitForSlotEvent
/// @param flags
/// @param pSlot
/// @param pReserved
/// @return
///
CK_RV C_WaitForSlotEvent(
		CK_FLAGS flags
		, CK_SLOT_ID_PTR pSlot
		, CK_VOID_PTR pReserved
);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_PARALLELMANAGEMENTFUNCTIONS_HPP
