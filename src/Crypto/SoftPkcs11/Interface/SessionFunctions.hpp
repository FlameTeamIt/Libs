#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_SESSIONFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_SESSIONFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief Opens a session between an application and a token
/// @param[in] slotId The slot's ID
/// @param[in] flags From CK_SESSION_INFO
/// @param[in] pApplication Passed to callback
/// @param[in] Notify Callback function
/// @param[out] phSession Gets session handle
/// @return See CKR_* values
///
CK_RV C_OpenSession(CK_SLOT_ID slotId, CK_FLAGS flags, CK_VOID_PTR pApplication
		, CK_NOTIFY Notify, CK_SESSION_HANDLE_PTR phSession);

///
/// @brief Closes a session between an application and a token
/// @param[in] hSession the Session's handle
/// @return See CKR_* values
///
CK_RV C_CloseSession(CK_SESSION_HANDLE hSession);

///
/// @brief Closes all sessions with a token
/// @param[in] slotId The token's slot
/// @return See CKR_* values
///
CK_RV C_CloseAllSessions(CK_SLOT_ID slotId);

///
/// @brief Obtains information about the session
/// @param[in] hSession The session's handle
/// @param[out] pInfo Receives session info
/// @return See CKR_* values
///
CK_RV C_GetSessionInfo(CK_SESSION_HANDLE hSession, CK_SESSION_INFO_PTR pInfo);

///
/// @brief Obtains the state of the cryptographic operation in a session
/// @param[in] hSession Session's handle
/// @param[out] pOperationState Gets state
/// @param[out] pulOperationStateLen Gets state length
/// @return See CKR_* values
///
CK_RV C_GetOperationState(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pOperationState
		, CK_ULONG_PTR pulOperationStateLen);

///
/// @brief Restores the state of the cryptographic operation in a session
/// @param[in] hSession Session's handle
/// @param[in] pOperationState Holds state
/// @param[in] ulOperationStateLen Holds state length
/// @param[in] hEncryptionKey Encryption/decryption key
/// @param[in] hAuthenticationKey Sign/verify key
/// @return See CKR_* values
///
CK_RV C_SetOperationState(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pOperationState
		, CK_ULONG ulOperationStateLen, CK_OBJECT_HANDLE hEncryptionKey
		, CK_OBJECT_HANDLE hAuthenticationKey);

///
/// @brief Logs a user into a token
/// @param hSession The session's handle
/// @param userType The user type
/// @param pPin The user's PIN
/// @param ulPinLen The length of the PIN
/// @return See CKR_* values
///
CK_RV C_Login(CK_SESSION_HANDLE hSession, CK_USER_TYPE userType
		, CK_UTF8CHAR_PTR pPin, CK_ULONG ulPinLen);

///
/// @brief Logs a user out from a token
/// @param[in] hSession The session's handle
/// @return See CKR_* values
///
CK_RV C_Logout(CK_SESSION_HANDLE hSession);

// v3.0

///
/// @brief C_LoginUser
/// @param hSession The session's handle
/// @param userType The user type
/// @param pPin The user's PIN
/// @param ulPinLen The length of the PIN
/// @param pUsername The user's name
/// @param ulUsernameLen The length of the user's name
/// @return See CKR_* values
///
CK_RV C_LoginUser(CK_SESSION_HANDLE hSession, CK_USER_TYPE userType
		, CK_UTF8CHAR_PTR pPin, CK_ULONG ulPinLen
		, CK_UTF8CHAR_PTR pUsername, CK_ULONG ulUsernameLen);

///
/// @brief C_SessionCancel
/// @param hSession The session's handle
/// @param flags Flags control which sessions are cancelled
/// @return See CKR_* values
///
CK_RV C_SessionCancel(CK_SESSION_HANDLE hSession, CK_FLAGS flags);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_SESSIONFUNCTIONS_HPP
