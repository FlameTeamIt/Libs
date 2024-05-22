#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_VERIFYFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_VERIFYFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief Initialize a verification operation, where the signature is an appendix
/// to the data, and plaintext cannot be recovered from the signature (e.g. DSA)
/// @param[in] hSession The session's handle
/// @param[in] pMechanism The verification mechanism
/// @param[in] hKey Verification key
/// @return See CKR_* values
///
CK_RV C_VerifyInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey);

///
/// @brief Verify a signature in a single-part operation, where the signature is
/// an appendix to the data, and plaintext cannot be recovered from the signature
/// @param[in] hSession The session's handle
/// @param[in] pData Signed data
/// @param[in] ulDataLen Length of signed data
/// @param[in] pSignature Signature
/// @param[in] ulSignatureLen Signature length
/// @return See CKR_* values
///
CK_RV C_Verify(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pData, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature, CK_ULONG ulSignatureLen);

///
/// @brief Continue a multiple-part verification operation, where the signature is
/// an appendix to the data, and plaintext cannot be recovered from the signature
/// @param[in] hSession The session's handle
/// @param[in] pPart Signed data
/// @param[in] ulPartLen Length of signed data
/// @return See CKR_* values
///
CK_RV C_VerifyUpdate(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pPart, CK_ULONG ulPartLen);

///
/// @brief Finish a multiple-part verification operation, checking the signature
/// @param[in] hSession The session's handle
/// @param[in] pSignature Signature to verify
/// @param[in] ulSignatureLen Signature length
/// @return See CKR_* values
///
CK_RV C_VerifyFinal(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pSignature
		, CK_ULONG ulSignatureLen);

///
/// @brief Initialize a signature verification operation, where the data is recovered
/// from the signature
/// @param[in] hSession The session's handle
/// @param[in] pMechanism The verification mechanism
/// @param[in] hKey Verification key
/// @return See CKR_* values
///
CK_RV C_VerifyRecoverInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey);

///
/// @brief Verify a signature in a single-part operation, where the data is recovered
/// from the signature
/// @param[in] hSession The session's handle
/// @param[in] pSignature Signature to verify
/// @param[in] ulSignatureLen Signature length
/// @param[out] pData Gets signed data
/// @param[out] pulDataLen Gets signed data length
/// @return See CKR_* values
///
CK_RV C_VerifyRecover(CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pSignature, CK_ULONG ulSignatureLen
		, CK_BYTE_PTR pData, CK_ULONG_PTR pulDataLen);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_VERIFYFUNCTIONS_HPP
