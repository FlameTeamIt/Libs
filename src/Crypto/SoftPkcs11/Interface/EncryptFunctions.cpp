#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/EncryptFunctions.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_EncryptInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.encryptCallbacks
			.init(hSession, pMechanism, hKey);
}

CK_RV C_Encrypt(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pEncryptedData
		, CK_ULONG_PTR pulEncryptedDataLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.encryptCallbacks
			.full(hSession, pData, ulDataLen, pEncryptedData, pulEncryptedDataLen);
}

CK_RV C_EncryptUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart
		, CK_ULONG ulPartLen
		, CK_BYTE_PTR pEncryptedPart
		, CK_ULONG_PTR pulEncryptedPartLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.encryptCallbacks
			.update(hSession, pPart, ulPartLen, pEncryptedPart, pulEncryptedPartLen);
}


CK_RV C_EncryptFinal(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pLastEncryptedPart
		, CK_ULONG_PTR pulLastEncryptedPartLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.encryptCallbacks
			.final(hSession, pLastEncryptedPart, pulLastEncryptedPartLen);
}

