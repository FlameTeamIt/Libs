#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/DecryptFunctions.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_DecryptInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.decrypt
			.init(hSession, pMechanism, hKey);
}

CK_RV C_Decrypt(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pEncryptedData
		, CK_ULONG ulEncryptedDataLen
		, CK_BYTE_PTR pData
		, CK_ULONG_PTR pulDataLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.decrypt
			.full(
					hSession, pEncryptedData, ulEncryptedDataLen, pData, pulDataLen
			);
}

CK_RV C_DecryptUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pEncryptedPart
		, CK_ULONG ulEncryptedPartLen
		, CK_BYTE_PTR pPart
		, CK_ULONG_PTR pulPartLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.decrypt
			.update(
					hSession, pEncryptedPart, ulEncryptedPartLen, pPart, pulPartLen
			);
}

CK_RV C_DecryptFinal(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pLastPart
		, CK_ULONG_PTR pulLastPartLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.decrypt
			.final(
					hSession, pLastPart, pulLastPartLen
			);
}
