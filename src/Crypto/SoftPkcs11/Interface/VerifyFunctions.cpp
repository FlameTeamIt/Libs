#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/VerifyFunctions.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_VerifyInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.verifyCallbacks
			.init(hSession, pMechanism, hKey);
}

CK_RV C_Verify(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature
		, CK_ULONG ulSignatureLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.verifyCallbacks
			.full(hSession, pData, ulDataLen, pSignature, ulSignatureLen);
}

CK_RV C_VerifyUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart
		, CK_ULONG ulPartLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.verifyCallbacks
			.update(hSession, pPart, ulPartLen);
}

CK_RV C_VerifyFinal(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pSignature
		, CK_ULONG ulSignatureLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.verifyCallbacks
			.final(hSession, pSignature, ulSignatureLen);
}

CK_RV C_VerifyRecoverInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.verifyCallbacks
			.recoverInit(hSession, pMechanism, hKey);
}

CK_RV C_VerifyRecover(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pSignature
		, CK_ULONG ulSignatureLen
		, CK_BYTE_PTR pData
		, CK_ULONG_PTR pulDataLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.verifyCallbacks
			.recoverFull(hSession, pSignature, ulSignatureLen, pData, pulDataLen);
}
