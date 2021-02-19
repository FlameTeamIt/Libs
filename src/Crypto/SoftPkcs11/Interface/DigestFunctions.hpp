#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DIGESTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DIGESTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// \brief C_DigestInit
/// \param hSession
/// \param pMechanism
/// \return
///
CK_RV C_DigestInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
);

///
/// \brief C_Digest
/// \param hSession
/// \param pData
/// \param ulDataLen
/// \param pDigest
/// \param pulDigestLen
/// \return
///
CK_RV C_Digest(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pDigest
		, CK_ULONG_PTR pulDigestLen
);

///
/// \brief C_DigestUpdate
/// \param hSession
/// \param pPart
/// \param ulPartLen
/// \return
///
CK_RV C_DigestUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart
		, CK_ULONG ulPartLen
);

///
/// \brief C_DigestKey
/// \param hSession
/// \param hKey
/// \return
///
CK_RV C_DigestKey(
		CK_SESSION_HANDLE hSession
		, CK_OBJECT_HANDLE hKey
);

///
/// \brief C_DigestFinal
/// \param hSession
/// \param pDigest
/// \param pulDigestLen
/// \return
///
CK_RV C_DigestFinal(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pDigest
		, CK_ULONG_PTR pulDigestLen
);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DIGESTFUNCTIONS_HPP
