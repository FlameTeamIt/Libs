#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/MessageVerifyFunctions.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_MessageVerifyInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.messageVerifyFunctions
			.verifyMessageInit(hSession, pMechanism, hKey);
}

CK_RV C_VerifyMessage(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature
		, CK_ULONG ulSignatureLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.messageVerifyFunctions
			.verifyMessage(
					hSession, pParameter, ulParameterLen
					, pData, ulDataLen
					, pSignature, ulSignatureLen
			);
}

CK_RV C_VerifyMessageBegin(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.messageVerifyFunctions
			.verifyMessageBegin(hSession, pParameter, ulParameterLen);
}

CK_RV C_VerifyMessageNext(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature
		, CK_ULONG ulSignatureLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.messageVerifyFunctions
			.verifyMessageNext(
					hSession, pParameter, ulParameterLen
					, pData, ulDataLen
					, pSignature, ulSignatureLen
			);
}

CK_RV C_MessageVerifyFinal(CK_SESSION_HANDLE hSession)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.messageVerifyFunctions
			.verifyMessageFinal(hSession);
}
