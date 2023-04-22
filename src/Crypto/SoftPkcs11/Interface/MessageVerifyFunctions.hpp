#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MESSAGEVERIFYFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MESSAGEVERIFYFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief C_MessageVerifyInit
/// @param hSession The session's handle
/// @param pMechanism The signing mechanism
/// @param hKey Handle of signing key
/// @return
///
CK_RV C_MessageVerifyInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
);

///
/// @brief C_VerifyMessage
/// @param hSession The session's handle
/// @param pParameter Message specific parameter
/// @param ulParameterLen Length of message specific parameter
/// @param pData Data to sign
/// @param ulDataLen Data to sign length
/// @param pSignature Signature
/// @param ulSignatureLen Signature length
/// @return
///
CK_RV C_VerifyMessage(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature
		, CK_ULONG ulSignatureLen
);

///
/// @brief C_VerifyMessageBegin
/// @param hSession The session's handle
/// @param pParameter Message specific parameter
/// @param ulParameterLen Length of message specific parameter
/// @return
///
CK_RV C_VerifyMessageBegin(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
);

///
/// @brief C_VerifyMessageNext
/// @param hSession The session's handle
/// @param pParameter Message specific parameter
/// @param ulParameterLen Length of message specific parameter
/// @param pData Data to sign
/// @param ulDataLen Data to sign length
/// @param pSignature Signature
/// @param ulSignatureLen Signature length
/// @return
///
CK_RV C_VerifyMessageNext(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature
		, CK_ULONG ulSignatureLen
);

///
/// @brief C_MessageVerifyFinal
/// @param hSession The session's handle
/// @return
///
CK_RV C_MessageVerifyFinal(CK_SESSION_HANDLE hSession);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MESSAGEVERIFYFUNCTIONS_HPP
