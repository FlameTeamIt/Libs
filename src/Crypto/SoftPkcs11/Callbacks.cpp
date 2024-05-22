#include <FlameIDE/../../src/Crypto/SoftPkcs11/Callbacks.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Version.hpp>

namespace flame_ide
{namespace soft_pkcs11
{

pkcs11::structs::FunctionList createFunctionList() noexcept
{
	pkcs11::structs::FunctionList functionList {
			pkcs11::structs::Version {
					pkcs11::enums::value(pkcs11::enums::Version::MAJOR)
					, pkcs11::enums::value(pkcs11::enums::Version::MINOR)
			}
			//
			, C_Initialize, C_Finalize, C_GetInfo, C_GetFunctionList
			//
			, C_GetSlotList, C_GetSlotInfo, C_GetTokenInfo, C_GetMechanismList
			, C_GetMechanismInfo, C_InitToken, C_InitPIN, C_SetPIN
			//
			, C_OpenSession, C_CloseSession, C_CloseAllSessions, C_GetSessionInfo
			, C_GetOperationState, C_SetOperationState, C_Login, C_Logout
			//
			, C_CreateObject, C_CopyObject, C_DestroyObject, C_GetObjectSize
			, C_GetAttributeValue, C_SetAttributeValue
			, C_FindObjectsInit, C_FindObjects, C_FindObjectsFinal
			//
			, C_EncryptInit, C_Encrypt, C_EncryptUpdate, C_EncryptFinal
			//
			, C_DecryptInit, C_Decrypt, C_DecryptUpdate, C_DecryptFinal
			//
			, C_DigestInit, C_Digest, C_DigestUpdate, C_DigestKey, C_DigestFinal
			//
			, C_SignInit, C_Sign, C_SignUpdate, C_SignFinal
			, C_SignRecoverInit, C_SignRecover
			//
			, C_VerifyInit, C_Verify, C_VerifyUpdate, C_VerifyFinal
			, C_VerifyRecoverInit, C_VerifyRecover
			//
			, C_DigestEncryptUpdate, C_DecryptDigestUpdate
			, C_SignEncryptUpdate, C_DecryptVerifyUpdate
			//
			, C_GenerateKey, C_GenerateKeyPair, C_WrapKey, C_UnwrapKey, C_DeriveKey
			//
			, C_SeedRandom, C_GenerateRandom
			//
			, C_GetFunctionStatus, C_CancelFunction, C_WaitForSlotEvent
	};

	return functionList;
}

pkcs11::structs::FunctionList3 createFunctionList3() noexcept
{
	pkcs11::structs::FunctionList3 functionList {
			pkcs11::structs::Version {
					pkcs11::enums::value(pkcs11::enums::Version::MAJOR)
					, pkcs11::enums::value(pkcs11::enums::Version::MINOR)
			}
			//
			, C_Initialize, C_Finalize, C_GetInfo, C_GetFunctionList
			//
			, C_GetSlotList, C_GetSlotInfo, C_GetTokenInfo, C_GetMechanismList
			, C_GetMechanismInfo, C_InitToken, C_InitPIN, C_SetPIN
			//
			, C_OpenSession, C_CloseSession, C_CloseAllSessions, C_GetSessionInfo
			, C_GetOperationState, C_SetOperationState, C_Login, C_Logout
			//
			, C_CreateObject, C_CopyObject, C_DestroyObject, C_GetObjectSize
			, C_GetAttributeValue, C_SetAttributeValue
			, C_FindObjectsInit, C_FindObjects, C_FindObjectsFinal
			//
			, C_EncryptInit, C_Encrypt, C_EncryptUpdate, C_EncryptFinal
			//
			, C_DecryptInit, C_Decrypt, C_DecryptUpdate, C_DecryptFinal
			//
			, C_DigestInit, C_Digest, C_DigestUpdate, C_DigestKey, C_DigestFinal
			//
			, C_SignInit, C_Sign, C_SignUpdate, C_SignFinal
			, C_SignRecoverInit, C_SignRecover
			//
			, C_VerifyInit, C_Verify, C_VerifyUpdate, C_VerifyFinal
			, C_VerifyRecoverInit, C_VerifyRecover
			//
			, C_DigestEncryptUpdate, C_DecryptDigestUpdate
			, C_SignEncryptUpdate, C_DecryptVerifyUpdate
			//
			, C_GenerateKey, C_GenerateKeyPair, C_WrapKey, C_UnwrapKey, C_DeriveKey
			//
			, C_SeedRandom, C_GenerateRandom
			//
			, C_GetFunctionStatus, C_CancelFunction, C_WaitForSlotEvent
			//
			, C_GetInterfaceList, C_GetInterface
			//
			, C_LoginUser, C_SessionCancel
			//
			, C_MessageEncryptInit, C_EncryptMessage
			, C_EncryptMessageBegin, C_EncryptMessageNext, C_MessageEncryptFinal
			//
			, C_MessageDecryptInit, C_DecryptMessage, C_DecryptMessageBegin
			, C_DecryptMessageNext, C_MessageDecryptFinal
			//
			, C_MessageSignInit, C_SignMessage
			, C_SignMessageBegin, C_SignMessageNext, C_MessageSignFinal
			//
			, C_MessageVerifyInit, C_VerifyMessage
			, C_VerifyMessageBegin, C_VerifyMessageNext, C_MessageVerifyFinal
	};

	return functionList;
}

}} // flame_ide::soft_pkcs11
