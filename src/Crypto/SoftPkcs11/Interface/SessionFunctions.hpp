#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_SESSIONFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_SESSIONFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief C_OpenSession
/// @param slotId
/// @param flags
/// @param pApplication
/// @param Notify
/// @param phSession
/// @return
///
CK_RV C_OpenSession(
		CK_SLOT_ID slotId
		, CK_FLAGS flags
		, CK_VOID_PTR pApplication
		, CK_NOTIFY Notify
		, CK_SESSION_HANDLE_PTR phSession
);

///
/// @brief C_CloseSession
/// @param hSession
/// @return
///
CK_RV C_CloseSession(CK_SESSION_HANDLE hSession);

///
/// @brief C_CloseAllSessions
/// @param slotId
/// @return
///
CK_RV C_CloseAllSessions(CK_SLOT_ID slotId);

///
/// @brief C_GetSessionInfo
/// @param hSession
/// @param pInfo
/// @return
///
CK_RV C_GetSessionInfo(
		CK_SESSION_HANDLE hSession
		, CK_SESSION_INFO_PTR pInfo
);

///
/// @brief C_GetOperationState
/// @param hSession
/// @param pOperationState
/// @param pulOperationStateLen
/// @return
///
CK_RV C_GetOperationState(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pOperationState
		, CK_ULONG_PTR pulOperationStateLen
);

///
/// @brief C_SetOperationState
/// @param hSession
/// @param pOperationState
/// @param ulOperationStateLen
/// @param hEncryptionKey
/// @param hAuthenticationKey
/// @return
///
CK_RV C_SetOperationState(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pOperationState
		, CK_ULONG ulOperationStateLen
		, CK_OBJECT_HANDLE hEncryptionKey
		, CK_OBJECT_HANDLE hAuthenticationKey
);

///
/// @brief C_Login
/// @param hSession
/// @param userType
/// @param pPin
/// @param ulPinLen
/// @return
///
CK_RV C_Login(
		CK_SESSION_HANDLE hSession
		, CK_USER_TYPE userType
		, CK_UTF8CHAR_PTR pPin
		, CK_ULONG ulPinLen
);

///
/// @brief C_Logout
/// @param hSession
/// @return
///
CK_RV C_Logout(CK_SESSION_HANDLE hSession);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_SESSIONFUNCTIONS_HPP
