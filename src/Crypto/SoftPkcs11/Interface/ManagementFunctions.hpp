#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MANAGEMENTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MANAGEMENTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief Obtains a list of slots in the system
/// @param[in] tokenPresent Only slots with tokens
/// @param[out] pSlotList Receives array of slot IDs
/// @param[out] pulCount Receives number of slots
/// @return See CKR_* values
///
CK_RV C_GetSlotList(
		CK_BBOOL tokenPresent
		, CK_SLOT_ID_PTR pSlotList
		, CK_ULONG_PTR pulCount
);

///
/// @brief Obtains information about a particular slot in the system
/// @param[in] slotId The ID of the slot
/// @param[out] pInfo Receives the slot information
/// @return See CKR_* values
///
CK_RV C_GetSlotInfo(
		CK_SLOT_ID slotId
		, CK_SLOT_INFO_PTR pInfo
);

///
/// @brief Obtains information about a particular token
/// @param[in] slotId ID of the token's slot
/// @param[out] pInfo receives the token information
/// @return See CKR_* values
///
CK_RV C_GetTokenInfo(CK_SLOT_ID slotId, CK_TOKEN_INFO_PTR pInfo);

///
/// @brief Obtains a list of mechanism types supported by a token
/// @param[in] slotId ID of token's slot
/// @param[out] pMechanismList Gets mechanism array
/// @param[out] pulCount Gets count of mechanisms
/// @return See CKR_* values
///
CK_RV C_GetMechanismList(CK_SLOT_ID slotId, CK_MECHANISM_TYPE_PTR pMechanismList
		, CK_ULONG_PTR pulCount);

///
/// @brief Obtains information about a particular mechanism possibly
/// supported by a token
/// @param[in] slotId ID of the token's slot
/// @param[in] type Type of mechanism
/// @param[out] pInfo Receives mechanism info
/// @return See CKR_* values
///
CK_RV C_GetMechanismInfo(CK_SLOT_ID slotId, CK_MECHANISM_TYPE type
		, CK_MECHANISM_INFO_PTR pInfo);

///
/// @brief Initializes a token
/// @param[in] slotId ID of the token's slot
/// @param[in] pPin The SO's initial PIN
/// @param[in] ulPinLen Length in bytes of the PIN
/// @param[in] pLabel 32-byte token label (blank padded)
/// @return See CKR_* values
///
CK_RV C_InitToken(CK_SLOT_ID slotId, CK_UTF8CHAR_PTR pPin, CK_ULONG ulPinLen
		, CK_UTF8CHAR_PTR pLabel);

///
/// @brief Initializes the normal user's PIN
/// @param[in] hSession The session's handle
/// @param[in] pPin The normal user's PIN
/// @param[in] ulPinLen Length in bytes of the PIN
/// @return See CKR_* values
///
CK_RV C_InitPIN(CK_SESSION_HANDLE hSession, CK_UTF8CHAR_PTR pPin, CK_ULONG ulPinLen);

///
/// @brief Modifies the PIN of the user who is logged in
/// @param[in] hSession The session's handle
/// @param[in] pOldPin The old PIN
/// @param[in] ulOldLen Length of the old PIN
/// @param[in] pNewPin The new PIN
/// @param[in] ulNewLen Length of the new PIN
/// @return See CKR_* values
///
CK_RV C_SetPIN(CK_SESSION_HANDLE hSession, CK_UTF8CHAR_PTR pOldPin, CK_ULONG ulOldLen
		, CK_UTF8CHAR_PTR pNewPin, CK_ULONG ulNewLen);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MANAGEMENTFUNCTIONS_HPP
