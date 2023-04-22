#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_FUNCTION_LIST_3_0_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_FUNCTION_LIST_3_0_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

/// @brief holding a Cryptoki spec version and pointers of appropriate types to
/// all the Cryptoki functions
struct FunctionList3: public WithParent<::CK_FUNCTION_LIST_3_0>
{
	FunctionList3() noexcept;
	FunctionList3(const FunctionList3 &functionList) noexcept;
	FunctionList3(const Parent &functionList) noexcept;

	FunctionList3(
			const decltype(Parent::version) &version
			, const decltype(Parent::C_Initialize) &initializeCallback
			, const decltype(Parent::C_Finalize) &finalizeCallback
			, const decltype(Parent::C_GetInfo) &getInfoCallback
			, const decltype(Parent::C_GetFunctionList) &getFunctionListCallback
			, const decltype(Parent::C_GetSlotList) &getSlotListCallback
			, const decltype(Parent::C_GetSlotInfo) &getSlotInfoCallback
			, const decltype(Parent::C_GetTokenInfo) &getTokenInfoCallback
			, const decltype(Parent::C_GetMechanismList) &getMechanismListCallback
			, const decltype(Parent::C_GetMechanismInfo) &getMechanismInfoCallback
			, const decltype(Parent::C_InitToken) &initTokenCallback
			, const decltype(Parent::C_InitPIN) &initPinCallback
			, const decltype(Parent::C_SetPIN) &setPinCallback
			, const decltype(Parent::C_OpenSession) &openSessionCallback
			, const decltype(Parent::C_CloseSession) &closeSessionCallback
			, const decltype(Parent::C_CloseAllSessions) &closeAllSessionsCallback
			, const decltype(Parent::C_GetSessionInfo) &getSessionInfoCallback
			, const decltype(Parent::C_GetOperationState) &getOperationStateCallback
			, const decltype(Parent::C_SetOperationState) &setOperationStateCallback
			, const decltype(Parent::C_Login) &loginCallback
			, const decltype(Parent::C_Logout) &logoutCallback
			, const decltype(Parent::C_CreateObject) &createObjectCallback
			, const decltype(Parent::C_CopyObject) &copyObjectCallback
			, const decltype(Parent::C_DestroyObject) &destroyObjectCallback
			, const decltype(Parent::C_GetObjectSize) &getObjectSizeCallback
			, const decltype(Parent::C_GetAttributeValue) &getAttributeValueCallback
			, const decltype(Parent::C_SetAttributeValue) &setAttributeValueCallback
			, const decltype(Parent::C_FindObjectsInit) &findObjectsInitCallback
			, const decltype(Parent::C_FindObjects) &findObjectsCallback
			, const decltype(Parent::C_FindObjectsFinal) &findObjectsFinalCallback
			, const decltype(Parent::C_EncryptInit) &encryptInitCallback
			, const decltype(Parent::C_Encrypt) &encryptCallback
			, const decltype(Parent::C_EncryptUpdate) &encryptUpdateCallback
			, const decltype(Parent::C_EncryptFinal) &encryptFinalCallback
			, const decltype(Parent::C_DecryptInit) &decryptInitCallback
			, const decltype(Parent::C_Decrypt) &decryptCallback
			, const decltype(Parent::C_DecryptUpdate) &decryptUpdateCallback
			, const decltype(Parent::C_DecryptFinal) &decryptFinalCallback
			, const decltype(Parent::C_DigestInit) &digestInitCallback
			, const decltype(Parent::C_Digest) &digestCallback
			, const decltype(Parent::C_DigestUpdate) &digestUpdateCallback
			, const decltype(Parent::C_DigestKey) &digestKeyCallback
			, const decltype(Parent::C_DigestFinal) &digestFinalCallback
			, const decltype(Parent::C_SignInit) &signInitCallback
			, const decltype(Parent::C_Sign) &signCallback
			, const decltype(Parent::C_SignUpdate) &signUpdateCallback
			, const decltype(Parent::C_SignFinal) &signFinalCallback
			, const decltype(Parent::C_SignRecoverInit) &signRecoverInitCallback
			, const decltype(Parent::C_SignRecover) &signRecoverCallback
			, const decltype(Parent::C_VerifyInit) &verifyInitCallback
			, const decltype(Parent::C_Verify) &verifyCallback
			, const decltype(Parent::C_VerifyUpdate) &verifyUpdateCallback
			, const decltype(Parent::C_VerifyFinal) &verifyFinalCallback
			, const decltype(Parent::C_VerifyRecoverInit) &verifyRecoverInitCallback
			, const decltype(Parent::C_VerifyRecover) &verifyRecoverCallback
			, const decltype(Parent::C_DigestEncryptUpdate) &digestEncryptUpdateCallback
			, const decltype(Parent::C_DecryptDigestUpdate) &decryptDigestUpdateCallback
			, const decltype(Parent::C_SignEncryptUpdate) &signEncryptUpdateCallback
			, const decltype(Parent::C_DecryptVerifyUpdate) &decryptVerifyUpdateCallback
			, const decltype(Parent::C_GenerateKey) &generateKeyCallback
			, const decltype(Parent::C_GenerateKeyPair) &generateKeyPairCallback
			, const decltype(Parent::C_WrapKey) &wrapKeyCallback
			, const decltype(Parent::C_UnwrapKey) &unwrapKeyCallback
			, const decltype(Parent::C_DeriveKey) &deriveKeyCallback
			, const decltype(Parent::C_SeedRandom) &seedRandomCallback
			, const decltype(Parent::C_GenerateRandom) &generateRandomCallback
			, const decltype(Parent::C_GetFunctionStatus) &getFunctionStatusCallback
			, const decltype(Parent::C_CancelFunction) &cancelFunctionCallback
			, const decltype(Parent::C_WaitForSlotEvent) &waitForSlotEventCallback

			, const decltype(Parent::C_GetInterfaceList) &getInterfaceListCallback
			, const decltype(Parent::C_GetInterface) &getInterfaceCallback
			, const decltype(Parent::C_LoginUser) &loginUserCallback
			, const decltype(Parent::C_SessionCancel) &sessionCancelCallback
			, const decltype(Parent::C_MessageEncryptInit) &messageEncryptInitCallback
			, const decltype(Parent::C_EncryptMessage) &encryptMessageCallback
			, const decltype(Parent::C_EncryptMessageBegin) &encryptMessageBeginCallback
			, const decltype(Parent::C_EncryptMessageNext) &encryptMessageNextCallback
			, const decltype(Parent::C_MessageEncryptFinal) &messageEncryptFinalCallback
			, const decltype(Parent::C_MessageDecryptInit) &messageDecryptInitCallback
			, const decltype(Parent::C_DecryptMessage) &decryptMessageCallback
			, const decltype(Parent::C_DecryptMessageBegin) &decryptMessageBeginCallback
			, const decltype(Parent::C_DecryptMessageNext) &decryptMessageNextCallback
			, const decltype(Parent::C_MessageDecryptFinal) &messageDecryptFinalCallback
			, const decltype(Parent::C_MessageSignInit) &messageSignInitCallback
			, const decltype(Parent::C_SignMessage) &signMessageCallback
			, const decltype(Parent::C_SignMessageBegin) &signMessageBeginCallback
			, const decltype(Parent::C_SignMessageNext) &signMessageNextCallback
			, const decltype(Parent::C_MessageSignFinal) &messageSignFinalCallback
			, const decltype(Parent::C_MessageVerifyInit) &messageVerifyInitCallback
			, const decltype(Parent::C_VerifyMessage) &verifyMessageCallback
			, const decltype(Parent::C_VerifyMessageBegin) &verifyMessageBeginCallback
			, const decltype(Parent::C_VerifyMessageNext) &verifyMessageNextCallback
			, const decltype(Parent::C_MessageVerifyFinal) &messageVerifyFinalCallback
	) noexcept;

	FunctionList3 &operator=(const FunctionList3 &functionList) noexcept;
	FunctionList3 &operator=(const Parent &functionList) noexcept;

	using Parent::version;
	using Parent::C_Initialize;
	using Parent::C_Finalize;
	using Parent::C_GetInfo;
	using Parent::C_GetFunctionList;
	using Parent::C_GetSlotList;
	using Parent::C_GetSlotInfo;
	using Parent::C_GetTokenInfo;
	using Parent::C_GetMechanismList;
	using Parent::C_GetMechanismInfo;
	using Parent::C_InitToken;
	using Parent::C_InitPIN;
	using Parent::C_SetPIN;
	using Parent::C_OpenSession;
	using Parent::C_CloseSession;
	using Parent::C_CloseAllSessions;
	using Parent::C_GetSessionInfo;
	using Parent::C_GetOperationState;
	using Parent::C_SetOperationState;
	using Parent::C_Login;
	using Parent::C_Logout;
	using Parent::C_CreateObject;
	using Parent::C_CopyObject;
	using Parent::C_DestroyObject;
	using Parent::C_GetObjectSize;
	using Parent::C_GetAttributeValue;
	using Parent::C_SetAttributeValue;
	using Parent::C_FindObjectsInit;
	using Parent::C_FindObjects;
	using Parent::C_FindObjectsFinal;
	using Parent::C_EncryptInit;
	using Parent::C_Encrypt;
	using Parent::C_EncryptUpdate;
	using Parent::C_EncryptFinal;
	using Parent::C_DecryptInit;
	using Parent::C_Decrypt;
	using Parent::C_DecryptUpdate;
	using Parent::C_DecryptFinal;
	using Parent::C_DigestInit;
	using Parent::C_Digest;
	using Parent::C_DigestUpdate;
	using Parent::C_DigestKey;
	using Parent::C_DigestFinal;
	using Parent::C_SignInit;
	using Parent::C_Sign;
	using Parent::C_SignUpdate;
	using Parent::C_SignFinal;
	using Parent::C_SignRecoverInit;
	using Parent::C_SignRecover;
	using Parent::C_VerifyInit;
	using Parent::C_Verify;
	using Parent::C_VerifyUpdate;
	using Parent::C_VerifyFinal;
	using Parent::C_VerifyRecoverInit;
	using Parent::C_VerifyRecover;
	using Parent::C_DigestEncryptUpdate;
	using Parent::C_DecryptDigestUpdate;
	using Parent::C_SignEncryptUpdate;
	using Parent::C_DecryptVerifyUpdate;
	using Parent::C_GenerateKey;
	using Parent::C_GenerateKeyPair;
	using Parent::C_WrapKey;
	using Parent::C_UnwrapKey;
	using Parent::C_DeriveKey;
	using Parent::C_SeedRandom;
	using Parent::C_GenerateRandom;
	using Parent::C_GetFunctionStatus;
	using Parent::C_CancelFunction;
	using Parent::C_WaitForSlotEvent;

	using Parent::C_GetInterfaceList;
	using Parent::C_GetInterface;
	using Parent::C_LoginUser;
	using Parent::C_SessionCancel;
	using Parent::C_MessageEncryptInit;
	using Parent::C_EncryptMessage;
	using Parent::C_EncryptMessageBegin;
	using Parent::C_EncryptMessageNext;
	using Parent::C_MessageEncryptFinal;
	using Parent::C_MessageDecryptInit;
	using Parent::C_DecryptMessage;
	using Parent::C_DecryptMessageBegin;
	using Parent::C_DecryptMessageNext;
	using Parent::C_MessageDecryptFinal;
	using Parent::C_MessageSignInit;
	using Parent::C_SignMessage;
	using Parent::C_SignMessageBegin;
	using Parent::C_SignMessageNext;
	using Parent::C_MessageSignFinal;
	using Parent::C_MessageVerifyInit;
	using Parent::C_VerifyMessage;
	using Parent::C_VerifyMessageBegin;
	using Parent::C_VerifyMessageNext;
	using Parent::C_MessageVerifyFinal;
};
using FunctionList3Ptr = ::CK_FUNCTION_LIST_3_0_PTR;
using FunctionList3PtrPtr = ::CK_FUNCTION_LIST_3_0_PTR_PTR;

}}} // flame_ide::pkcs11::structs

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_STRUCTS_FUNCTION_LIST_3_0_HPP
