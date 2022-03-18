#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/MessageEncryptFunctions.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_MessageEncryptInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.message
			.encrypt
			.init(hSession, pMechanism, hKey);
}

CK_RV C_EncryptMessage(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pAssociatedData
		, CK_ULONG ulAssociatedDataLen
		, CK_BYTE_PTR pPlaintext
		, CK_ULONG ulPlaintextLen
		, CK_BYTE_PTR pCiphertext
		, CK_ULONG_PTR pulCiphertextLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.message
			.encrypt
			.full(
					hSession, pParameter, ulParameterLen
					, pAssociatedData, ulAssociatedDataLen
					, pPlaintext, ulPlaintextLen
					, pCiphertext, pulCiphertextLen
			);
}

CK_RV C_EncryptMessageBegin(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pAssociatedData
		, CK_ULONG ulAssociatedDataLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.message
			.encrypt
			.begin(
					hSession, pParameter, ulParameterLen
					, pAssociatedData, ulAssociatedDataLen
			);
}

CK_RV C_EncryptMessageNext(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pPlaintextPart
		, CK_ULONG ulPlaintextPartLen
		, CK_BYTE_PTR pCiphertextPart
		, CK_ULONG_PTR pulCiphertextPartLen
		, CK_FLAGS flags
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.message
			.encrypt
			.next(
					hSession, pParameter, ulParameterLen
					, pPlaintextPart, ulPlaintextPartLen
					, pCiphertextPart, pulCiphertextPartLen
					, flags
			);
}

CK_RV C_MessageEncryptFinal(CK_SESSION_HANDLE hSession)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.message
			.encrypt
			.final(hSession);
}
