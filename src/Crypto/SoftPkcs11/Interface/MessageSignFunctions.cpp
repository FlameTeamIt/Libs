#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/MessageSignFunctions.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_MessageSignInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.message
			.sign
			.init(hSession, pMechanism, hKey);
}

CK_RV C_SignMessage(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature
		, CK_ULONG_PTR pulSignatureLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.message
			.sign
			.full(
					hSession, pParameter, ulParameterLen
					, pData, ulDataLen
					, pSignature, pulSignatureLen
			);
}

CK_RV C_SignMessageBegin(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.message
			.sign
			.begin(hSession, pParameter, ulParameterLen);
}

CK_RV C_SignMessageNext(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature
		, CK_ULONG_PTR pulSignatureLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.message
			.sign
			.next(
					hSession, pParameter, ulParameterLen
					, pData, ulDataLen
					, pSignature, pulSignatureLen
			);
}

CK_RV C_MessageSignFinal(CK_SESSION_HANDLE hSession)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.message
			.sign
			.final(hSession);
}
