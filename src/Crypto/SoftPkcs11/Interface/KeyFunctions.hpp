#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_KEYFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_KEYFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// \brief C_GenerateKey
/// \param hSession
/// \param pMechanism
/// \param pTemplate
/// \param ulCount
/// \param phKey
/// \return
///
CK_RV C_GenerateKey(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulCount
		, CK_OBJECT_HANDLE_PTR phKey
);

///
/// \brief C_GenerateKeyPair
/// \param hSession
/// \param pMechanism
/// \param pPublicKeyTemplate
/// \param ulPublicKeyAttributeCount
/// \param pPrivateKeyTemplate
/// \param ulPrivateKeyAttributeCount
/// \param phPublicKey
/// \param phPrivateKey
/// \return
///
CK_RV C_GenerateKeyPair(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_ATTRIBUTE_PTR pPublicKeyTemplate
		, CK_ULONG ulPublicKeyAttributeCount
		, CK_ATTRIBUTE_PTR pPrivateKeyTemplate
		, CK_ULONG ulPrivateKeyAttributeCount
		, CK_OBJECT_HANDLE_PTR phPublicKey
		, CK_OBJECT_HANDLE_PTR phPrivateKey
);

///
/// \brief C_WrapKey
/// \param hSession
/// \param pMechanism
/// \param hWrappingKey
/// \param hKey
/// \param pWrappedKey
/// \param pulWrappedKeyLen
/// \return
///
CK_RV C_WrapKey(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hWrappingKey
		, CK_OBJECT_HANDLE hKey
		, CK_BYTE_PTR pWrappedKey
		, CK_ULONG_PTR pulWrappedKeyLen
);

///
/// \brief C_UnwrapKey
/// \param hSession
/// \param pMechanism
/// \param hUnwrappingKey
/// \param pWrappedKey
/// \param ulWrappedKeyLen
/// \param pTemplate
/// \param ulAttributeCount
/// \param phKey
/// \return
///
CK_RV C_UnwrapKey(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hUnwrappingKey
		, CK_BYTE_PTR pWrappedKey
		, CK_ULONG ulWrappedKeyLen
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulAttributeCount
		, CK_OBJECT_HANDLE_PTR phKey
);

///
/// \brief C_DeriveKey
/// \param hSession
/// \param pMechanism
/// \param hBaseKey
/// \param pTemplate
/// \param ulAttributeCount
/// \param phKey
/// \return
///
CK_RV C_DeriveKey(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hBaseKey
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulAttributeCount
		, CK_OBJECT_HANDLE_PTR phKey
);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_KEYFUNCTIONS_HPP
