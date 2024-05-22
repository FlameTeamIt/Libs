#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DUALOPERATIONFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DUALOPERATIONFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief Continue a multiple-part digesting and encryption operation
/// @param[in] hSession Session's handle
/// @param[in] pPart The plain text data
/// @param[in] ulPartLen Plain text length
/// @param[out] pEncryptedPart Gets cipher text
/// @param[out] pulEncryptedPartLen Gets cipher text length
/// @return See CKR_* values
///
CK_RV C_DigestEncryptUpdate(CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart, CK_ULONG ulPartLen
		, CK_BYTE_PTR pEncryptedPart, CK_ULONG_PTR pulEncryptedPartLen);

///
/// @brief Continue a multiple-part decryption and digesting operation
/// @param[in] hSession Session's handle
/// @param[in] pEncryptedPart Cipher text
/// @param[in] ulEncryptedPartLen Cipher text length
/// @param[out] pPart Gets plain text
/// @param[out] pulPartLen Gets plain text legth
/// @return See CKR_* values
///
CK_RV C_DecryptDigestUpdate(CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pEncryptedPart, CK_ULONG ulEncryptedPartLen
		, CK_BYTE_PTR pPart, CK_ULONG_PTR pulPartLen
);

///
/// @brief Continue a multiple-part signing and encryption operation
/// @param[in] hSession Session's handle
/// @param[in] pPart The plain text data
/// @param[in] ulPartLen Plain text length
/// @param[out] pEncryptedPart Gets cipher text
/// @param[out] pulEncryptedPartLen Gets cipher text length
/// @return See CKR_* values
///
CK_RV C_SignEncryptUpdate(CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart, CK_ULONG ulPartLen
		, CK_BYTE_PTR pEncryptedPart, CK_ULONG_PTR pulEncryptedPartLen
);

///
/// @brief Continue a multiple-part decryption and verify operation
/// @param[in] hSession Session's handle
/// @param[in] pEncryptedPart Cipher text
/// @param[in] ulEncryptedPartLen Cipher text length
/// @param[out] pPart Gets plain text
/// @param[out] pulPartLen Gets plain text length
/// @return See CKR_* values
///
CK_RV C_DecryptVerifyUpdate(CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pEncryptedPart, CK_ULONG ulEncryptedPartLen
		, CK_BYTE_PTR pPart, CK_ULONG_PTR pulPartLen);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DUALOPERATIONFUNCTIONS_HPP
