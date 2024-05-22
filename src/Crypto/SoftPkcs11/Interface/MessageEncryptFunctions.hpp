#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MESSAGEENCRYPTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MESSAGEENCRYPTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief C_MessageEncryptInit
/// @param hSession The session's handle
/// @param pMechanism The encryption mechanism
/// @param hKey Handle of encryption key
/// @return
///
CK_RV C_MessageEncryptInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
);

///
/// @brief C_EncryptMessage
/// @param hSession The session's handle
/// @param pParameter Message specific parameter
/// @param ulParameterLen Length of message specific parameter
/// @param pAssociatedData AEAD Associated data
/// @param ulAssociatedDataLen AEAD Associated data length
/// @param pPlaintext Plain text
/// @param ulPlaintextLen Plain text length
/// @param pCiphertext Gets cipher text
/// @param pulCiphertextLen Gets cipher text length
/// @return
///
CK_RV C_EncryptMessage(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pAssociatedData
		, CK_ULONG ulAssociatedDataLen
		, CK_BYTE_PTR pPlaintext
		, CK_ULONG ulPlaintextLen
		, CK_BYTE_PTR pCiphertext
		, CK_ULONG_PTR pulCiphertextLen
);

///
/// @brief C_EncryptMessageBegin
/// @param hSession The session's handle
/// @param pParameter Message specific parameter
/// @param ulParameterLen Length of message specific parameter
/// @param pAssociatedData AEAD Associated data
/// @param ulAssociatedDataLen AEAD Associated data length
/// @return
///
CK_RV C_EncryptMessageBegin(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pAssociatedData
		, CK_ULONG ulAssociatedDataLen
);

///
/// @brief C_EncryptMessageNext
/// @param hSession The session's handle
/// @param pParameter Message specific parameter
/// @param ulParameterLen Length of message specific parameter
/// @param pPlaintextPart Plain text
/// @param ulPlaintextPartLen Plain text length
/// @param pCiphertextPart Gets cipher text
/// @param pulCiphertextPartLen Gets cipher text length
/// @param flags Multi mode flag
/// @return
///
CK_RV C_EncryptMessageNext(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pPlaintextPart
		, CK_ULONG ulPlaintextPartLen
		, CK_BYTE_PTR pCiphertextPart
		, CK_ULONG_PTR pulCiphertextPartLen
		, CK_FLAGS flags
);

///
/// @brief C_MessageEncryptFinal
/// @param hSession The session's handle
/// @return
///
CK_RV C_MessageEncryptFinal(CK_SESSION_HANDLE hSession);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MESSAGEENCRYPTFUNCTIONS_HPP
