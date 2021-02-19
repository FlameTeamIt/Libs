#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_ENCRYPTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_ENCRYPTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// \brief C_EncryptInit
/// \param hSession
/// \param pMechanism
/// \param hKey
/// \return
///
CK_RV C_EncryptInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
);

///
/// \brief C_Encrypt
/// \param hSession
/// \param pData
/// \param ulDataLen
/// \param pEncryptedData
/// \param pulEncryptedDataLen
/// \return
///
CK_RV C_Encrypt(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pEncryptedData
		, CK_ULONG_PTR pulEncryptedDataLen
);

///
/// \brief C_EncryptUpdate
/// \param hSession
/// \param pPart
/// \param ulPartLen
/// \param pEncryptedPart
/// \param pulEncryptedPartLen
/// \return
///
CK_RV C_EncryptUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pPart
		, CK_ULONG ulPartLen
		, CK_BYTE_PTR pEncryptedPart
		, CK_ULONG_PTR pulEncryptedPartLen
);

///
/// \brief C_EncryptFinal
/// \param hSession
/// \param pLastEncryptedPart
/// \param pulLastEncryptedPartLen
/// \return
///
CK_RV C_EncryptFinal(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pLastEncryptedPart
		, CK_ULONG_PTR pulLastEncryptedPartLen
);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_ENCRYPTFUNCTIONS_HPP
