#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DECRYPTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DECRYPTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief Initialize a decryption operation
/// @param[in] hSession The session's handle
/// @param[in] pMechanism The decryption mechanism
/// @param[in] hKey Handle of decryption key
/// @return See CKR_* values
///
CK_RV C_DecryptInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey);

///
/// @brief Decrypt encrypted data in a single part
/// @param[in] hSession Session's handle
/// @param[in] pEncryptedData Cipher text
/// @param[in] ulEncryptedDataLen Ciphertext length
/// @param[out] pData Gets plain text
/// @param[out] pulDataLen Gets plain text size
/// @return See CKR_* values
///
CK_RV C_Decrypt(CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pEncryptedData, CK_ULONG ulEncryptedDataLen
		, CK_BYTE_PTR pData, CK_ULONG_PTR pulDataLen);

///
/// @brief Continue a multiple-part decryption operation
/// @param[in] hSession Session's handle
/// @param[in] pEncryptedPart Encrypted data
/// @param[in] ulEncryptedPartLen Input length
/// @param[out] pPart Gets plain text
/// @param[out] pulPartLen Plain text size
/// @return See CKR_* values
///
CK_RV C_DecryptUpdate(CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pEncryptedPart, CK_ULONG ulEncryptedPartLen
		, CK_BYTE_PTR pPart, CK_ULONG_PTR pulPartLen);

///
/// @brief Finish a multiple-part decryption operation
/// @param[in] hSession The session's handle
/// @param[out] pLastPart Gets plain text
/// @param[out] pulLastPartLen Plain text size
/// @return See CKR_* values
///
CK_RV C_DecryptFinal(CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pLastPart, CK_ULONG_PTR pulLastPartLen);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DECRYPTFUNCTIONS_HPP
