#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/DualOperationFunctions.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_DigestEncryptUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart
		, CK_ULONG ulPartLen
		, CK_BYTE_PTR pEncryptedPart
		, CK_ULONG_PTR pulEncryptedPartLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.dualOperations
			.digestEncryptUpdate(
					hSession, pPart, ulPartLen, pEncryptedPart, pulEncryptedPartLen
			);
}

CK_RV C_DecryptDigestUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pEncryptedPart
		, CK_ULONG ulEncryptedPartLen
		, CK_BYTE_PTR pPart
		, CK_ULONG_PTR pulPartLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.dualOperations
			.decryptDigestUpdate(
					hSession, pEncryptedPart, ulEncryptedPartLen, pPart, pulPartLen
			);
}

CK_RV C_SignEncryptUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart
		, CK_ULONG ulPartLen
		, CK_BYTE_PTR pEncryptedPart
		, CK_ULONG_PTR pulEncryptedPartLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.dualOperations
			.signEncryptUpdate(
					hSession, pPart, ulPartLen, pEncryptedPart, pulEncryptedPartLen
			);
}

CK_RV C_DecryptVerifyUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pEncryptedPart
		, CK_ULONG ulEncryptedPartLen
		, CK_BYTE_PTR pPart
		, CK_ULONG_PTR pulPartLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.dualOperations
			.decryptVerifyUpdate(
					hSession, pEncryptedPart, ulEncryptedPartLen, pPart, pulPartLen
			);
}
