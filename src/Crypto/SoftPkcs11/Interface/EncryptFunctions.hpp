#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_ENCRYPTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_ENCRYPTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief Initializes an encryption operation
/// @param[in] hSession The session's handle
/// @param[in] pMechanism The encryption mechanism
/// @param[in] hKey Handle of encryption key
/// @return See CKR_* values
///
CK_RV C_EncryptInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey);

///
/// @brief Encrypt single-part data
/// @param[in] hSession Session's handle
/// @param[in] pData The plaintext data
/// @param[in] ulDataLen Bytes of plaintext
/// @param[out] pEncryptedData Gets ciphertext
/// @param[out] pulEncryptedDataLen Gets c-text size
/// @return See CKR_* values
///
CK_RV C_Encrypt(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pData, CK_ULONG ulDataLen
		, CK_BYTE_PTR pEncryptedData, CK_ULONG_PTR pulEncryptedDataLen);

///
/// @brief Continue a multiple-part encryption operation
/// @param[in] hSession Session's handle
/// @param[in] pPart The plaintext data
/// @param[in] ulPartLen Plaintext data len
/// @param[out] pEncryptedPart Gets ciphertext
/// @param[out] pulEncryptedPartLen Gets ciphertext size
/// @return See CKR_* values
///
CK_RV C_EncryptUpdate(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pPart, CK_ULONG ulPartLen
		, CK_BYTE_PTR pEncryptedPart, CK_ULONG_PTR pulEncryptedPartLen);

///
/// @brief Finish a multiple-part encryption operation
/// @param[in] hSession Session handle
/// @param[out] pLastEncryptedPart Last ciphertext
/// @param[out] pulLastEncryptedPartLen Gets last size
/// @return See CKR_* values
///
CK_RV C_EncryptFinal(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pLastEncryptedPart
		, CK_ULONG_PTR pulLastEncryptedPartLen);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_ENCRYPTFUNCTIONS_HPP
