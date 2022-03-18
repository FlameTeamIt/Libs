#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MESSAGEDECRYPTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MESSAGEDECRYPTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief C_MessageDecryptInit
/// @param hSession The session's handle
/// @param pMechanism The decryption mechanism
/// @param hKey Handle of decryption key
/// @return
///
CK_RV C_MessageDecryptInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
);

///
/// @brief C_DecryptMessage
/// @param hSession The session's handle
/// @param pParameter Message specific parameter
/// @param ulParameterLen Length of message specific parameter
/// @param pAssociatedData AEAD Associated data
/// @param ulAssociatedDataLen AEAD Associated data length
/// @param pCiphertext Cipher text
/// @param ulCiphertextLen Cipher text length
/// @param pPlaintext Gets plain text
/// @param pulPlaintextLen Gets plain text length
/// @return
///
CK_RV C_DecryptMessage(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pAssociatedData
		, CK_ULONG ulAssociatedDataLen
		, CK_BYTE_PTR pCiphertext
		, CK_ULONG ulCiphertextLen
		, CK_BYTE_PTR pPlaintext
		, CK_ULONG_PTR pulPlaintextLen
);

///
/// @brief C_DecryptMessageBegin
/// @param hSession The session's handle
/// @param pParameter Message specific parameter
/// @param ulParameterLen Length of message specific parameter
/// @param pAssociatedData AEAD Associated data
/// @param ulAssociatedDataLen AEAD Associated data length
/// @return
///
CK_RV C_DecryptMessageBegin(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pAssociatedData
		, CK_ULONG ulAssociatedDataLen
);

///
/// @brief C_DecryptMessageNext
/// @param hSession The session's handle
/// @param pParameter Message specific parameter
/// @param ulParameterLen Length of message specific parameter
/// @param pCiphertext Cipher text
/// @param ulCiphertextLen Cipher text length
/// @param pPlaintext Gets plain text
/// @param pulPlaintextLen Gets plain text length
/// @param flags Multi mode flag
/// @return
///
CK_RV C_DecryptMessageNext(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pCiphertext
		, CK_ULONG ulCiphertextLen
		, CK_BYTE_PTR pPlaintext
		, CK_ULONG_PTR pulPlaintextLen
		, CK_FLAGS flags
);

///
/// @brief C_MessageDecryptFinal
/// @param hSession The session's handle
/// @return
///
CK_RV C_MessageDecryptFinal(CK_SESSION_HANDLE hSession);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MESSAGEDECRYPTFUNCTIONS_HPP
