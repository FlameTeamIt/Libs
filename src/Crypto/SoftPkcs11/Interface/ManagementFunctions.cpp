#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/ManagementFunctions.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_GetSlotList(
		CK_BBOOL tokenPresent
		, CK_SLOT_ID_PTR pSlotList
		, CK_ULONG_PTR pulCount
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.managementCallbacks
			.getSlotList(tokenPresent, pSlotList, pulCount);
}

CK_RV C_GetSlotInfo(
		CK_SLOT_ID slotId
		, CK_SLOT_INFO_PTR pInfo
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.managementCallbacks
			.getSlotInfo(slotId, pInfo);
}

CK_RV C_GetTokenInfo(
		CK_SLOT_ID slotId
		, CK_TOKEN_INFO_PTR pInfo
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.managementCallbacks
			.getTokenInfo(slotId, pInfo);
}

CK_RV C_GetMechanismList(
		CK_SLOT_ID slotId
		, CK_MECHANISM_TYPE_PTR pMechanismList
		, CK_ULONG_PTR pulCount
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.managementCallbacks
			.getMechanismList(slotId, pMechanismList, pulCount);
}

CK_RV C_GetMechanismInfo(
		CK_SLOT_ID slotId
		, CK_MECHANISM_TYPE type
		, CK_MECHANISM_INFO_PTR pInfo
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.managementCallbacks
			.getMechanismInfo(slotId, type, pInfo);
}

CK_RV C_InitToken(
		CK_SLOT_ID slotId
		, CK_UTF8CHAR_PTR pPin
		, CK_ULONG ulPinLen
		, CK_UTF8CHAR_PTR pLabel
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.managementCallbacks
			.initToken(slotId, pPin, ulPinLen, pLabel);
}

CK_RV C_InitPIN(
		CK_SESSION_HANDLE hSession
		, CK_UTF8CHAR_PTR pPin
		, CK_ULONG ulPinLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.managementCallbacks
			.initPin(hSession, pPin, ulPinLen);
}

CK_RV C_SetPIN(
		CK_SESSION_HANDLE hSession
		, CK_UTF8CHAR_PTR pOldPin
		, CK_ULONG ulOldLen
		, CK_UTF8CHAR_PTR pNewPin
		, CK_ULONG ulNewLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.managementCallbacks
			.setPin(hSession, pOldPin, ulOldLen, pNewPin, ulNewLen);
}
