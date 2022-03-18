#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/SessionFunctions.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_OpenSession(
		CK_SLOT_ID slotId
		, CK_FLAGS flags
		, CK_VOID_PTR pApplication
		, CK_NOTIFY Notify
		, CK_SESSION_HANDLE_PTR phSession
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.sessionCallbacks
			.open(slotId, flags, pApplication, Notify, phSession);
}

CK_RV C_CloseSession(CK_SESSION_HANDLE hSession)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.sessionCallbacks
			.close(hSession);
}

CK_RV C_CloseAllSessions(CK_SLOT_ID slotId)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.sessionCallbacks
			.closeAll(slotId);
}

CK_RV C_GetSessionInfo(
		CK_SESSION_HANDLE hSession
		, CK_SESSION_INFO_PTR pInfo
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.sessionCallbacks
			.getInfo(hSession, pInfo);
}

CK_RV C_GetOperationState(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pOperationState
		, CK_ULONG_PTR pulOperationStateLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.sessionCallbacks
			.getOperationState(hSession, pOperationState, pulOperationStateLen);
}

CK_RV C_SetOperationState(
		CK_SESSION_HANDLE hSession
		, CK_BYTE_PTR pOperationState
		, CK_ULONG ulOperationStateLen
		, CK_OBJECT_HANDLE hEncryptionKey
		, CK_OBJECT_HANDLE hAuthenticationKey
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.sessionCallbacks
			.setOperationState(
					hSession, pOperationState, ulOperationStateLen
					, hEncryptionKey, hAuthenticationKey
			);
}

CK_RV C_Login(
		CK_SESSION_HANDLE hSession
		, CK_USER_TYPE userType
		, CK_UTF8CHAR_PTR pPin
		, CK_ULONG ulPinLen
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.sessionCallbacks
			.login(hSession, userType, pPin, ulPinLen);
}

CK_RV C_Logout(CK_SESSION_HANDLE hSession)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.sessionCallbacks
			.logout(hSession);
}

// v3.0

CK_RV C_LoginUser(CK_SESSION_HANDLE hSession, CK_USER_TYPE userType
		, CK_UTF8CHAR_PTR pPin, CK_ULONG ulPinLen
		, CK_UTF8CHAR_PTR pUsername, CK_ULONG ulUsernameLen)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.sessionCallbacks
			.loginUser(
					hSession, userType
					, pPin, ulPinLen
					, pUsername, ulUsernameLen
			);
}

CK_RV C_SessionCancel(CK_SESSION_HANDLE hSession, CK_FLAGS flags)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.sessionCallbacks
			.sessionCancel(hSession, flags);
}
