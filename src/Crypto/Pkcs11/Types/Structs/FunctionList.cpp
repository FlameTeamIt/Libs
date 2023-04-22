#include <FlameIDE/Crypto/Pkcs11/Types/Structs/FunctionList.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace structs
{

FunctionList::FunctionList() noexcept
		: FunctionList(Parent{})
{}

FunctionList::FunctionList(const FunctionList &functionList) noexcept
		: FunctionList(static_cast<const Parent &>(functionList))
{}

FunctionList::FunctionList(const Parent &functionList) noexcept
{
	operator=(functionList);
}

FunctionList &FunctionList::operator=(const FunctionList &functionList) noexcept
{
	return operator=(static_cast<const Parent &>(functionList));
}

FunctionList::FunctionList(
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
) noexcept
{
	this->version = version;
	this->C_Initialize = initializeCallback;
	this->C_Finalize = finalizeCallback;
	this->C_GetInfo = getInfoCallback;
	this->C_GetFunctionList = getFunctionListCallback;
	this->C_GetSlotList = getSlotListCallback;
	this->C_GetSlotInfo = getSlotInfoCallback;
	this->C_GetTokenInfo = getTokenInfoCallback;
	this->C_GetMechanismList = getMechanismListCallback;
	this->C_GetMechanismInfo = getMechanismInfoCallback;
	this->C_InitToken = initTokenCallback;
	this->C_InitPIN = initPinCallback;
	this->C_SetPIN = setPinCallback;
	this->C_OpenSession = openSessionCallback;
	this->C_CloseSession = closeSessionCallback;
	this->C_CloseAllSessions = closeAllSessionsCallback;
	this->C_GetSessionInfo = getSessionInfoCallback;
	this->C_GetOperationState = getOperationStateCallback;
	this->C_SetOperationState = setOperationStateCallback;
	this->C_Login = loginCallback;
	this->C_Logout = logoutCallback;
	this->C_CreateObject = createObjectCallback;
	this->C_CopyObject = copyObjectCallback;
	this->C_DestroyObject = destroyObjectCallback;
	this->C_GetObjectSize = getObjectSizeCallback;
	this->C_GetAttributeValue = getAttributeValueCallback;
	this->C_SetAttributeValue = setAttributeValueCallback;
	this->C_FindObjectsInit = findObjectsInitCallback;
	this->C_FindObjects = findObjectsCallback;
	this->C_FindObjectsFinal = findObjectsFinalCallback;
	this->C_EncryptInit = encryptInitCallback;
	this->C_Encrypt = encryptCallback;
	this->C_EncryptUpdate = encryptUpdateCallback;
	this->C_EncryptFinal = encryptFinalCallback;
	this->C_DecryptInit = decryptInitCallback;
	this->C_Decrypt = decryptCallback;
	this->C_DecryptUpdate = decryptUpdateCallback;
	this->C_DecryptFinal = decryptFinalCallback;
	this->C_DigestInit = digestInitCallback;
	this->C_Digest = digestCallback;
	this->C_DigestUpdate = digestUpdateCallback;
	this->C_DigestKey = digestKeyCallback;
	this->C_DigestFinal = digestFinalCallback;
	this->C_SignInit = signInitCallback;
	this->C_Sign = signCallback;
	this->C_SignUpdate = signUpdateCallback;
	this->C_SignFinal = signFinalCallback;
	this->C_SignRecoverInit = signRecoverInitCallback;
	this->C_SignRecover = signRecoverCallback;
	this->C_VerifyInit = verifyInitCallback;
	this->C_Verify = verifyCallback;
	this->C_VerifyUpdate = verifyUpdateCallback;
	this->C_VerifyFinal = verifyFinalCallback;
	this->C_VerifyRecoverInit = verifyRecoverInitCallback;
	this->C_VerifyRecover = verifyRecoverCallback;
	this->C_DigestEncryptUpdate = digestEncryptUpdateCallback;
	this->C_DecryptDigestUpdate = decryptDigestUpdateCallback;
	this->C_SignEncryptUpdate = signEncryptUpdateCallback;
	this->C_DecryptVerifyUpdate = decryptVerifyUpdateCallback;
	this->C_GenerateKey = generateKeyCallback;
	this->C_GenerateKeyPair = generateKeyPairCallback;
	this->C_WrapKey = wrapKeyCallback;
	this->C_UnwrapKey = unwrapKeyCallback;
	this->C_DeriveKey = deriveKeyCallback;
	this->C_SeedRandom = seedRandomCallback;
	this->C_GenerateRandom = generateRandomCallback;
	this->C_GetFunctionStatus = getFunctionStatusCallback;
	this->C_CancelFunction = cancelFunctionCallback;
	this->C_WaitForSlotEvent = waitForSlotEventCallback;
}

FunctionList &FunctionList::operator=(const Parent &functionList) noexcept
{
	version = functionList.version;
	C_Initialize = functionList.C_Initialize;
	C_Finalize = functionList.C_Finalize;
	C_GetInfo = functionList.C_GetInfo;
	C_GetFunctionList = functionList.C_GetFunctionList;
	C_GetSlotList = functionList.C_GetSlotList;
	C_GetSlotInfo = functionList.C_GetSlotInfo;
	C_GetTokenInfo = functionList.C_GetTokenInfo;
	C_GetMechanismList = functionList.C_GetMechanismList;
	C_GetMechanismInfo = functionList.C_GetMechanismInfo;
	C_InitToken = functionList.C_InitToken;
	C_InitPIN = functionList.C_InitPIN;
	C_SetPIN = functionList.C_SetPIN;
	C_OpenSession = functionList.C_OpenSession;
	C_CloseSession = functionList.C_CloseSession;
	C_CloseAllSessions = functionList.C_CloseAllSessions;
	C_GetSessionInfo = functionList.C_GetSessionInfo;
	C_GetOperationState = functionList.C_GetOperationState;
	C_SetOperationState = functionList.C_SetOperationState;
	C_Login = functionList.C_Login;
	C_Logout = functionList.C_Logout;
	C_CreateObject = functionList.C_CreateObject;
	C_CopyObject = functionList.C_CopyObject;
	C_DestroyObject = functionList.C_DestroyObject;
	C_GetObjectSize = functionList.C_GetObjectSize;
	C_GetAttributeValue = functionList.C_GetAttributeValue;
	C_SetAttributeValue = functionList.C_SetAttributeValue;
	C_FindObjectsInit = functionList.C_FindObjectsInit;
	C_FindObjects = functionList.C_FindObjects;
	C_FindObjectsFinal = functionList.C_FindObjectsFinal;
	C_EncryptInit = functionList.C_EncryptInit;
	C_Encrypt = functionList.C_Encrypt;
	C_EncryptUpdate = functionList.C_EncryptUpdate;
	C_EncryptFinal = functionList.C_EncryptFinal;
	C_DecryptInit = functionList.C_DecryptInit;
	C_Decrypt = functionList.C_Decrypt;
	C_DecryptUpdate = functionList.C_DecryptUpdate;
	C_DecryptFinal = functionList.C_DecryptFinal;
	C_DigestInit = functionList.C_DigestInit;
	C_Digest = functionList.C_Digest;
	C_DigestUpdate = functionList.C_DigestUpdate;
	C_DigestKey = functionList.C_DigestKey;
	C_DigestFinal = functionList.C_DigestFinal;
	C_SignInit = functionList.C_SignInit;
	C_Sign = functionList.C_Sign;
	C_SignUpdate = functionList.C_SignUpdate;
	C_SignFinal = functionList.C_SignFinal;
	C_SignRecoverInit = functionList.C_SignRecoverInit;
	C_SignRecover = functionList.C_SignRecover;
	C_VerifyInit = functionList.C_VerifyInit;
	C_Verify = functionList.C_Verify;
	C_VerifyUpdate = functionList.C_VerifyUpdate;
	C_VerifyFinal = functionList.C_VerifyFinal;
	C_VerifyRecoverInit = functionList.C_VerifyRecoverInit;
	C_VerifyRecover = functionList.C_VerifyRecover;
	C_DigestEncryptUpdate = functionList.C_DigestEncryptUpdate;
	C_DecryptDigestUpdate = functionList.C_DecryptDigestUpdate;
	C_SignEncryptUpdate = functionList.C_SignEncryptUpdate;
	C_DecryptVerifyUpdate = functionList.C_DecryptVerifyUpdate;
	C_GenerateKey = functionList.C_GenerateKey;
	C_GenerateKeyPair = functionList.C_GenerateKeyPair;
	C_WrapKey = functionList.C_WrapKey;
	C_UnwrapKey = functionList.C_UnwrapKey;
	C_DeriveKey = functionList.C_DeriveKey;
	C_SeedRandom = functionList.C_SeedRandom;
	C_GenerateRandom = functionList.C_GenerateRandom;
	C_GetFunctionStatus = functionList.C_GetFunctionStatus;
	C_CancelFunction = functionList.C_CancelFunction;
	C_WaitForSlotEvent = functionList.C_WaitForSlotEvent;
	return *this;
}

}}} // flame_ide::pkcs11::structs
