#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MESSAGESIGNFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MESSAGESIGNFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief C_MessageSignInit
/// @param hSession The session's handle
/// @param pMechanism The signing mechanism
/// @param hKey Handle of signing key
/// @return
///
CK_RV C_MessageSignInit(
		CK_SESSION_HANDLE hSession
		, CK_MECHANISM_PTR pMechanism
		, CK_OBJECT_HANDLE hKey
);

///
/// @brief C_SignMessage
/// @param hSession The session's handle
/// @param pParameter Message specific parameter
/// @param ulParameterLen Length of message specific parameter
/// @param pData Data to sign
/// @param ulDataLen Data to sign length
/// @param pSignature Gets signature
/// @param pulSignatureLen Gets signature length
/// @return
///
CK_RV C_SignMessage(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature
		, CK_ULONG_PTR pulSignatureLen
);

///
/// @brief C_SignMessageBegin
/// @param hSession The session's handle
/// @param pParameter Message specific parameter
/// @param ulParameterLen Length of message specific parameter
/// @return
///
CK_RV C_SignMessageBegin(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
);

///
/// @brief C_SignMessageNext
/// @param hSession The session's handle
/// @param pParameter Message specific parameter
/// @param ulParameterLen Length of message specific parameter
/// @param pData Data to sign
/// @param ulDataLen Data to sign length
/// @param pSignature Gets signature
/// @param pulSignatureLen Gets signature length
/// @return
///
CK_RV C_SignMessageNext(
		CK_SESSION_HANDLE hSession
		, CK_VOID_PTR pParameter
		, CK_ULONG ulParameterLen
		, CK_BYTE_PTR pData
		, CK_ULONG ulDataLen
		, CK_BYTE_PTR pSignature
		, CK_ULONG_PTR pulSignatureLen
);

///
/// @brief C_MessageSignFinal
/// @param hSession The session's handle
/// @return
///
CK_RV C_MessageSignFinal(CK_SESSION_HANDLE hSession);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_MESSAGESIGNFUNCTIONS_HPP
