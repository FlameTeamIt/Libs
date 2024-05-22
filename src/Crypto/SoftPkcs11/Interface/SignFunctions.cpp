#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/SignFunctions.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_SignInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.sign
			.init(hSession, pMechanism, hKey);
}

CK_RV C_Sign(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature
		, CK_ULONG_PTR pulSignatureLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.sign
			.full(hSession, pData, ulDataLen, pSignature, pulSignatureLen);
}

CK_RV C_SignUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart
		, CK_ULONG ulPartLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.sign
			.update(hSession, pPart, ulPartLen);
}

CK_RV C_SignFinal(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pSignature
		, CK_ULONG_PTR pulSignatureLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.sign
			.final(hSession, pSignature, pulSignatureLen);
}

CK_RV C_SignRecoverInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.sign
			.recoverInit(hSession, pMechanism, hKey);
}

CK_RV C_SignRecover(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature
		, CK_ULONG_PTR pulSignatureLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.sign
			.recoverFull(hSession, pData, ulDataLen, pSignature, pulSignatureLen);
}
