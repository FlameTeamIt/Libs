#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_KEYFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_KEYFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief Generate a secret key, creating a new key object
/// @param[in] hSession The session's handle
/// @param[in] pMechanism Key generation mechanism
/// @param[in] pTemplate Template for new key
/// @param[in] ulCount Count of attributes in template
/// @param[out] phKey Gets handle of new key
/// @return See CKR_* values
///
CK_RV C_GenerateKey(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism
		, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount, CK_OBJECT_HANDLE_PTR phKey);

///
/// @brief Generate a public/private key pair, creating new key objects
/// @param[in] hSession Session handle
/// @param[in] pMechanism Key-gen mechanism
/// @param[in] pPublicKeyTemplate Template for public key
/// @param[in] ulPublicKeyAttributeCount Count public attributes
/// @param[in] pPrivateKeyTemplate Template for private key
/// @param[in] ulPrivateKeyAttributeCount Count private attributes
/// @param[out] phPublicKey Gets public key handle
/// @param[out] phPrivateKey Gets private key handle
/// @return See CKR_* values
///
CK_RV C_GenerateKeyPair(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism
		, CK_ATTRIBUTE_PTR pPublicKeyTemplate, CK_ULONG ulPublicKeyAttributeCount
		, CK_ATTRIBUTE_PTR pPrivateKeyTemplate, CK_ULONG ulPrivateKeyAttributeCount
		, CK_OBJECT_HANDLE_PTR phPublicKey, CK_OBJECT_HANDLE_PTR phPrivateKey);

///
/// @brief Wrap (i.e., encrypt) a key
/// @param[in] hSession The session's handle
/// @param[in] pMechanism The wrapping mechanism
/// @param[in] hWrappingKey Wrapping key
/// @param[in] hKey Key to be wrapped
/// @param[out] pWrappedKey Gets wrapped key
/// @param[out] pulWrappedKeyLen Gets wrapped key size
/// @return See CKR_* values
///
CK_RV C_WrapKey(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hWrappingKey, CK_OBJECT_HANDLE hKey
		, CK_BYTE_PTR pWrappedKey, CK_ULONG_PTR pulWrappedKeyLen);

///
/// @brief Unwrap (decrypt) a wrapped key, creating a new key object
/// @param[in] hSession Session's handle
/// @param[in] pMechanism Unwrapping mech.
/// @param[in] hUnwrappingKey Unwrapping key
/// @param[in] pWrappedKey The wrapped key
/// @param[in] ulWrappedKeyLen Wrapped key len
/// @param[in] pTemplate New key template
/// @param[in] ulAttributeCount Template length
/// @param[out] phKey Gets new handle
/// @return See CKR_* values
///
CK_RV C_UnwrapKey(CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism, CK_OBJECT_HANDLE hUnwrappingKey
		, CK_BYTE_PTR pWrappedKey, CK_ULONG ulWrappedKeyLen
		, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulAttributeCount
		, CK_OBJECT_HANDLE_PTR phKey);

///
/// @brief Derive a key from a base key, creating a new key object
/// @param[in] hSession Session's handle
/// @param[in] pMechanism Key deriv. mech.
/// @param[in] hBaseKey Base key
/// @param[in] pTemplate New key template
/// @param[in] ulAttributeCount Template length
/// @param[out] phKey Gets new handle
/// @return See CKR_* values
///
CK_RV C_DeriveKey(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hBaseKey, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulAttributeCount
		, CK_OBJECT_HANDLE_PTR phKey);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_KEYFUNCTIONS_HPP
