#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/MessageDecryptFunctions.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_MessageDecryptInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.messageDecriptionFunctions
			.decryptMessageInit(hSession, pMechanism, hKey);
}

CK_RV C_DecryptMessage(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pAssociatedData
		, CK_ULONG ulAssociatedDataLen
		, CK_BYTE_PTR pCiphertext
		, CK_ULONG ulCiphertextLen
		, CK_BYTE_PTR pPlaintext
		, CK_ULONG_PTR pulPlaintextLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.messageDecriptionFunctions
			.decryptMessage(
					hSession, pParameter, ulParameterLen
					, pAssociatedData, ulAssociatedDataLen
					, pCiphertext, ulCiphertextLen
					, pPlaintext, pulPlaintextLen
			);
}

CK_RV C_DecryptMessageBegin(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pAssociatedData
		, CK_ULONG ulAssociatedDataLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.messageDecriptionFunctions
			.decryptMessageBegin(
					hSession, pParameter, ulParameterLen
					, pAssociatedData, ulAssociatedDataLen
			);
}

CK_RV C_DecryptMessageNext(
	CK_SESSION_HANDLE hSession
	, CK_VOID_PTR pParameter
	, CK_ULONG ulParameterLen
	, CK_BYTE_PTR pCiphertext
	, CK_ULONG ulCiphertextLen
	, CK_BYTE_PTR pPlaintext
	, CK_ULONG_PTR pulPlaintextLen
	, CK_FLAGS flags
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.messageDecriptionFunctions
			.decryptMessageNext(
					hSession, pParameter, ulParameterLen
					, pCiphertext, ulCiphertextLen
					, pPlaintext, pulPlaintextLen
					, flags
			);
}

CK_RV C_MessageDecryptFinal(CK_SESSION_HANDLE hSession)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.messageDecriptionFunctions
			.decryptMessageFinal(hSession);
}
