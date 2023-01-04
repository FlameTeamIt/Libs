#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/DigestFunctions.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_DigestInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.digest
			.init(hSession, pMechanism);
}

CK_RV C_Digest(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pDigest
		, CK_ULONG_PTR pulDigestLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.digest
			.full(hSession, pData, ulDataLen, pDigest, pulDigestLen);
}

CK_RV C_DigestUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart
		, CK_ULONG ulPartLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.digest
			.update(hSession, pPart, ulPartLen);
}

CK_RV C_DigestKey(
		CK_SESSION_HANDLE hSession
		, CK_OBJECT_HANDLE hKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.digest
			.key(hSession, hKey);
}

CK_RV C_DigestFinal(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pDigest
		, CK_ULONG_PTR pulDigestLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.digest
			.final(hSession, pDigest, pulDigestLen);
}
