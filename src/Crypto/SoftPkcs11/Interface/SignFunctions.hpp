#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_SIGNFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_SIGNFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// \brief C_SignInit
/// \param hSession
/// \param pMechanism
/// \param hKey
/// \return
///
CK_RV C_SignInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
);

///
/// \brief C_Sign
/// \param hSession
/// \param pData
/// \param ulDataLen
/// \param pSignature
/// \param pulSignatureLen
/// \return
///
CK_RV C_Sign(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature
		, CK_ULONG_PTR pulSignatureLen
);

///
/// \brief C_SignUpdate
/// \param hSession
/// \param pPart
/// \param ulPartLen
/// \return
///
CK_RV C_SignUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart
		, CK_ULONG ulPartLen
);

///
/// \brief C_SignFinal
/// \param hSession
/// \param pSignature
/// \param pulSignatureLen
/// \return
///
CK_RV C_SignFinal(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pSignature
		, CK_ULONG_PTR pulSignatureLen
);

///
/// \brief C_SignRecoverInit
/// \param hSession
/// \param pMechanism
/// \param hKey
/// \return
///
CK_RV C_SignRecoverInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
);

///
/// \brief C_SignRecover
/// \param hSession
/// \param pData
/// \param ulDataLen
/// \param pSignature
/// \param pulSignatureLen
/// \return
///
CK_RV C_SignRecover(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature
		, CK_ULONG_PTR pulSignatureLen
);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_SIGNFUNCTIONS_HPP
