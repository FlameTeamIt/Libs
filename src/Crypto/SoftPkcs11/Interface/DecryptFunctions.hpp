#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DECRYPTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DECRYPTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// \brief C_DecryptInit
/// \param hSession
/// \param pMechanism
/// \param hKey
/// \return
///
CK_RV C_DecryptInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
);

///
/// \brief C_Decrypt
/// \param hSession
/// \param pEncryptedData
/// \param ulEncryptedDataLen
/// \param pData
/// \param pulDataLen
/// \return
///
CK_RV C_Decrypt(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pEncryptedData
		, CK_ULONG ulEncryptedDataLen
		, CK_BYTE_PTR pData
		, CK_ULONG_PTR pulDataLen
);

///
/// \brief C_DecryptUpdate
/// \param hSession
/// \param pEncryptedPart
/// \param ulEncryptedPartLen
/// \param pPart
/// \param pulPartLen
/// \return
///
CK_RV C_DecryptUpdate(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pEncryptedPart
		, CK_ULONG ulEncryptedPartLen
		, CK_BYTE_PTR pPart
		, CK_ULONG_PTR pulPartLen
);

///
/// \brief C_DecryptFinal
/// \param hSession
/// \param pLastPart
/// \param pulLastPartLen
/// \return
///
CK_RV C_DecryptFinal(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pLastPart
		, CK_ULONG_PTR pulLastPartLen
);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_DECRYPTFUNCTIONS_HPP
