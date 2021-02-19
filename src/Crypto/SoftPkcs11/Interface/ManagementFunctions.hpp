#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MANAGEMENTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MANAGEMENTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// \brief C_GetSlotList
/// \param tokenPresent
/// \param pSlotList
/// \param pulCount
/// \return
///
CK_RV C_GetSlotList(
		CK_BBOOL tokenPresent
		, CK_SLOT_ID_PTR pSlotList
		, CK_ULONG_PTR pulCount
);

///
/// \brief C_GetSlotInfo
/// \param slotId
/// \param pInfo
/// \return
///
CK_RV C_GetSlotInfo(
		CK_SLOT_ID slotId
		, CK_SLOT_INFO_PTR pInfo
);

///
/// \brief C_GetTokenInfo
/// \param slotId
/// \param pInfo
/// \return
///
CK_RV C_GetTokenInfo(
		CK_SLOT_ID slotId
		, CK_TOKEN_INFO_PTR pInfo
);

///
/// \brief C_GetMechanismList
/// \param slotId
/// \param pMechanismList
/// \param pulCount
/// \return
///
CK_RV C_GetMechanismList(
		CK_SLOT_ID slotId
		, CK_MECHANISM_TYPE_PTR pMechanismList
		, CK_ULONG_PTR pulCount
);

///
/// \brief C_GetMechanismInfo
/// \param slotId
/// \param type
/// \param pInfo
/// \return
///
CK_RV C_GetMechanismInfo(
		CK_SLOT_ID slotId
		, CK_MECHANISM_TYPE type
		, CK_MECHANISM_INFO_PTR pInfo
);

///
/// \brief C_InitToken
/// \param slotId
/// \param pPin
/// \param ulPinLen
/// \param pLabel
/// \return
///
CK_RV C_InitToken(
		CK_SLOT_ID slotId
		, CK_UTF8CHAR_PTR pPin
		, CK_ULONG ulPinLen
		, CK_UTF8CHAR_PTR pLabel
);

///
/// \brief C_InitPIN
/// \param hSession
/// \param pPin
/// \param ulPinLen
/// \return
///
CK_RV C_InitPIN(
		CK_SESSION_HANDLE hSession
		, CK_UTF8CHAR_PTR pPin
		, CK_ULONG ulPinLen
);

///
/// \brief C_SetPIN
/// \param hSession
/// \param pOldPin
/// \param ulOldLen
/// \param pNewPin
/// \param ulNewLen
/// \return
///
CK_RV C_SetPIN(
		CK_SESSION_HANDLE hSession
		, CK_UTF8CHAR_PTR pOldPin
		, CK_ULONG ulOldLen
		, CK_UTF8CHAR_PTR pNewPin
		, CK_ULONG ulNewLen
);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MANAGEMENTFUNCTIONS_HPP
