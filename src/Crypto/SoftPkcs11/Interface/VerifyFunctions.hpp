#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_VERIFYFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_VERIFYFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// \brief C_VerifyInit
/// \param hSession
/// \param pMechanism
/// \param hKey
/// \return
///
CK_RV C_VerifyInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
);

///
/// \brief C_Verify
/// \param hSession
/// \param pData
/// \param ulDataLen
/// \param pSignature
/// \param ulSignatureLen
/// \return
///
CK_RV C_Verify(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature
		, CK_ULONG ulSignatureLen
);

///
/// \brief C_VerifyUpdate
/// \param hSession
/// \param pPart
/// \param ulPartLen
/// \return
///
CK_RV C_VerifyUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart
		, CK_ULONG ulPartLen
);

///
/// \brief C_VerifyFinal
/// \param hSession
/// \param pSignature
/// \param ulSignatureLen
/// \return
///
CK_RV C_VerifyFinal(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pSignature
		, CK_ULONG ulSignatureLen
);

///
/// \brief C_VerifyRecoverInit
/// \param hSession
/// \param pMechanism
/// \param hKey
/// \return
///
CK_RV C_VerifyRecoverInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
);

///
/// \brief C_VerifyRecover
/// \param hSession
/// \param pSignature
/// \param ulSignatureLen
/// \param pData
/// \param pulDataLen
/// \return
///
CK_RV C_VerifyRecover(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pSignature
		, CK_ULONG ulSignatureLen
		, CK_BYTE_PTR pData
		, CK_ULONG_PTR pulDataLen
);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_VERIFYFUNCTIONS_HPP
