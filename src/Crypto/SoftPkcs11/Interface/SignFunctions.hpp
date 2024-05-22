#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_SIGNFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_SIGNFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief Initialize a signature (private key encryption) operation, where
/// the signature is (will be) an appendix to the data, and plain text cannot be
/// recovered from the signature
/// @param[in] hSession The session's handle
/// @param[in] pMechanism The signature mechanism
/// @param[in] hKey Handle of signature key
/// @return See CKR_* values
///
CK_RV C_SignInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey);

///
/// @brief Sign (encrypts with private key) data in a single part, where
/// the signature is (will be) an appendix to the data, and plaintext cannot be
/// recovered from the signature
/// @param[in] hSession The session's handle
/// @param[in] pData The data to sign
/// @param[in] ulDataLen Count of bytes to sign
/// @param[out] pSignature Gets the signature
/// @param[out] pulSignatureLen Gets signature length
/// @return See CKR_* values
///
CK_RV C_Sign(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pData, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature, CK_ULONG_PTR pulSignatureLen);

///
/// @brief Сontinue a multiple-part signature operation, where the signature is
/// (will be) an appendix to the data, and plaintext cannot be recovered from
/// the signature
/// @param[in] hSessionThe session's handle
/// @param[in] pPart The data to sign
/// @param[in] ulPartLen Count of bytes to sign
/// @return See CKR_* values
///
CK_RV C_SignUpdate(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pPart, CK_ULONG ulPartLen);

///
/// @brief Finish a multiple-part signature operation, returning the signature
/// @param[in] hSession The session's handle
/// @param[out] pSignature Gets the signature
/// @param[out] pulSignatureLen Gets signature length
/// @return See CKR_* values
///
CK_RV C_SignFinal(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pSignature
		, CK_ULONG_PTR pulSignatureLen);

///
/// @brief Initialize a signature operation, where the data can be recovered from
/// the signature
/// @param[in] hSession The session's handle
/// @param[in] pMechanism The signature mechanism
/// @param[in] hKey Handle of the signature key
/// @return See CKR_* values
///
CK_RV C_SignRecoverInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey);

///
/// @brief Sign data in a single operation, where the data can be recovered from
/// the signature
/// @param[in] hSession The session's handle
/// @param[in] pData The data to sign
/// @param[in] ulDataLen Count of bytes to sign
/// @param[out] pSignature Gets the signature
/// @param[out] pulSignatureLen Gets signature length
/// @return See CKR_* values
///
CK_RV C_SignRecover(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pData, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature, CK_ULONG_PTR pulSignatureLen);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_SIGNFUNCTIONS_HPP
