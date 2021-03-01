#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DIGESTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DIGESTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief Initializes a message-digesting operation
/// @param[in] hSession The session's handle
/// @param[in] pMechanism The digesting mechanism
/// @return See CKR_* values
///
CK_RV C_DigestInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism);

///
/// @brief Digest data in a single part
/// @param[in] hSession The session's handle
/// @param[in] pData Data to be digested
/// @param[in] ulDataLen Bytes of data to digest
/// @param[out] pDigest Gets the message digest
/// @param[out] pulDigestLen Gets digest length
/// @return See CKR_* values
///
CK_RV C_Digest(CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pData, CK_ULONG ulDataLen
		, CK_BYTE_PTR pDigest, CK_ULONG_PTR pulDigestLen);

///
/// @brief Continue a multiple-part message-digesting operation
/// @param[in] hSession The session's handle
/// @param[in] pPart Data to be digested
/// @param[in] ulPartLen Bytes of data to be digested
/// @return See CKR_* values
///
CK_RV C_DigestUpdate(CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart, CK_ULONG ulPartLen);

///
/// @brief Continue a multi-part message-digesting operation, by digesting
/// the value of a secret key as part of the data already digested
/// @param[in] hSession The session's handle
/// @param[in] hKey Secret key to digest
/// @return See CKR_* values
///
CK_RV C_DigestKey(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hKey);

///
/// @brief Finish a multiple-part message-digesting operation
/// @param hSession The session's handle
/// @param pDigest Gets the message digest
/// @param pulDigestLen Gets byte count of digest
/// @return See CKR_* values
///
CK_RV C_DigestFinal(CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pDigest, CK_ULONG_PTR pulDigestLen);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DIGESTFUNCTIONS_HPP
