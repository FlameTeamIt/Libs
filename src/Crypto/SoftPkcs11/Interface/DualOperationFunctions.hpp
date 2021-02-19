#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DUALOPERATIONFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DUALOPERATIONFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// \brief C_DigestEncryptUpdate
/// \param hSession
/// \param pPart
/// \param ulPartLen
/// \param pEncryptedPart
/// \param pulEncryptedPartLen
/// \return
///
CK_RV C_DigestEncryptUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart
		, CK_ULONG ulPartLen
		, CK_BYTE_PTR pEncryptedPart
		, CK_ULONG_PTR pulEncryptedPartLen
);

///
/// \brief C_DecryptDigestUpdate
/// \param hSession
/// \param pEncryptedPart
/// \param ulEncryptedPartLen
/// \param pPart
/// \param pulPartLen
/// \return
///
CK_RV C_DecryptDigestUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pEncryptedPart
		, CK_ULONG ulEncryptedPartLen
		, CK_BYTE_PTR pPart
		, CK_ULONG_PTR pulPartLen
);

///
/// \brief C_SignEncryptUpdate
/// \param hSession
/// \param pPart
/// \param ulPartLen
/// \param pEncryptedPart
/// \param pulEncryptedPartLen
/// \return
///
CK_RV C_SignEncryptUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart
		, CK_ULONG ulPartLen
		, CK_BYTE_PTR pEncryptedPart
		, CK_ULONG_PTR pulEncryptedPartLen
);

///
/// \brief C_DecryptVerifyUpdate
/// \param hSession
/// \param pEncryptedPart
/// \param ulEncryptedPartLen
/// \param pPart
/// \param pulPartLen
/// \return
///
CK_RV C_DecryptVerifyUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pEncryptedPart
		, CK_ULONG ulEncryptedPartLen
		, CK_BYTE_PTR pPart
		, CK_ULONG_PTR pulPartLen
);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DUALOPERATIONFUNCTIONS_HPP
