#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/KeyFunctions.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_GenerateKey(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulCount
		, CK_OBJECT_HANDLE_PTR phKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.key
			.generateKey(hSession, pMechanism, pTemplate, ulCount, phKey);
}

CK_RV C_GenerateKeyPair(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_ATTRIBUTE_PTR pPublicKeyTemplate
		, CK_ULONG ulPublicKeyAttributeCount
		, CK_ATTRIBUTE_PTR pPrivateKeyTemplate
		, CK_ULONG ulPrivateKeyAttributeCount
		, CK_OBJECT_HANDLE_PTR phPublicKey
		, CK_OBJECT_HANDLE_PTR phPrivateKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.key
			.generateKeyPair(
					hSession, pMechanism
					, pPublicKeyTemplate, ulPublicKeyAttributeCount
					, pPrivateKeyTemplate, ulPrivateKeyAttributeCount
					, phPublicKey, phPrivateKey
			);
}

CK_RV C_WrapKey(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hWrappingKey
		, CK_OBJECT_HANDLE hKey
		, CK_BYTE_PTR pWrappedKey
		, CK_ULONG_PTR pulWrappedKeyLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.key
			.wrapKey(
					hSession, pMechanism
					, hWrappingKey, hKey
					, pWrappedKey, pulWrappedKeyLen
			);
}

CK_RV C_UnwrapKey(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hUnwrappingKey
		, CK_BYTE_PTR pWrappedKey
		, CK_ULONG ulWrappedKeyLen
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulAttributeCount
		, CK_OBJECT_HANDLE_PTR phKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.key
			.unwrapKey(
					hSession, pMechanism
					, hUnwrappingKey, pWrappedKey, ulWrappedKeyLen
					, pTemplate, ulAttributeCount, phKey
			);
}

CK_RV C_DeriveKey(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hBaseKey
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulAttributeCount
		, CK_OBJECT_HANDLE_PTR phKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.key
			.deriveKey(
					hSession, pMechanism, hBaseKey
					, pTemplate, ulAttributeCount
					, phKey
			);
}
