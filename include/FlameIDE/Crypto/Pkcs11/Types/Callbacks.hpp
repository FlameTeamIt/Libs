#ifndef FLAMEDE_CRYPRO_PKCS11_TYPES_CALLBACKS_HPP
#define FLAMEDE_CRYPRO_PKCS11_TYPES_CALLBACKS_HPP

#include <FlameIDE/Crypto/Pkcs11/CryptokiPkcs11.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace callbacks
{

using Notify = CK_NOTIFY;

using CreateMutex = CK_CREATEMUTEX;
using DestroyMutex = CK_DESTROYMUTEX;
using LockMutex = CK_LOCKMUTEX;
using UnlockeMutex = CK_UNLOCKMUTEX;

/* General-purpose */

using Initialize = CK_C_Initialize;
using Finalize = CK_C_Finalize;
using GetInfo = CK_C_GetInfo;
using GetFunctionList = CK_C_GetFunctionList;
using GetSlotList = CK_C_GetSlotList;
using GetSlotInfo = CK_C_GetSlotInfo;
using GetTokenInfo = CK_C_GetTokenInfo;
using GetMechanismList = CK_C_GetMechanismList;
using GetMechanismInfo = CK_C_GetMechanismInfo;
using InitToken = CK_C_InitToken;
using InitPIN = CK_C_InitPIN;
using SetPIN = CK_C_SetPIN;


/* Session management */

using OpenSession = CK_C_OpenSession;
using CloseSession = CK_C_CloseSession;
using CloseAllSessions = CK_C_CloseAllSessions;
using GetSessionInfo = CK_C_GetSessionInfo;
using GetOperationState = CK_C_GetOperationState;
using SetOperationState = CK_C_SetOperationState;
using Login = CK_C_Login;
using Logout = CK_C_Logout;


/* Object management */

using CreateObject = CK_C_CreateObject;
using CopyObject = CK_C_CopyObject;
using DestroyObject = CK_C_DestroyObject;
using GetObjectSize = CK_C_GetObjectSize;
using GetAttributeValue = CK_C_GetAttributeValue;
using SetAttributeValue = CK_C_SetAttributeValue;
using FindObjectsInit = CK_C_FindObjectsInit;
using FindObjects = CK_C_FindObjects;
using FindObjectsFinal = CK_C_FindObjectsFinal;


/* Encryption and decryption */

using EncryptInit = CK_C_EncryptInit;
using Encrypt = CK_C_Encrypt;
using EncryptUpdate = CK_C_EncryptUpdate;
using EncryptFinal = CK_C_EncryptFinal;

using DecryptInit = CK_C_DecryptInit;
using Decrypt = CK_C_Decrypt;
using DecryptUpdate = CK_C_DecryptUpdate;
using DecryptFinal = CK_C_DecryptFinal;


/* Message digesting */

using DecryptInit = CK_C_DecryptInit;
using Decrypt = CK_C_Decrypt;
using DecryptUpdate = CK_C_DecryptUpdate;
using DecryptFinal = CK_C_DecryptFinal;


/* Signing and MACing */

using SignInit = CK_C_SignInit;
using Sign = CK_C_Sign;
using SignUpdate = CK_C_SignUpdate;
using SignFinal = CK_C_SignFinal;

using SignRecoverInit = CK_C_SignRecoverInit;
using SignRecover = CK_C_SignRecover;


/* Verifying signatures and MACs */

using VerifyInit = CK_C_VerifyInit;
using Verify = CK_C_Verify;
using VerifyUpdate = CK_C_VerifyUpdate;
using VerifyFinal = CK_C_VerifyFinal;

using VerifyRecoverInit = CK_C_VerifyRecoverInit;
using VerifyRecover = CK_C_VerifyRecover;


/* Dual-function cryptographic operations */

using DigestEncryptUpdate = CK_C_DigestEncryptUpdate;
using DecryptDigestUpdate = CK_C_DecryptDigestUpdate;

using SignEncryptUpdate = CK_C_SignEncryptUpdate;
using DecryptVerifyUpdate = CK_C_DecryptVerifyUpdate;


/* Key management */

using GenerateKey = CK_C_GenerateKey;
using GenerateKeyPair = CK_C_GenerateKeyPair;
using WrapKey = CK_C_WrapKey;
using UnwrapKey = CK_C_UnwrapKey;
using DeriveKey = CK_C_DeriveKey;
using SeedRandom = CK_C_SeedRandom;
using GenerateRandom = CK_C_GenerateRandom;


/* Parallel function management */

using GetFunctionStatus = CK_C_GetFunctionStatus;
using CancelFunction = CK_C_CancelFunction;
using WaitForSlotEvent = CK_C_WaitForSlotEvent;

} // namespace callbacks
} // namespace pkcs11
} // namespace flame_ide

#endif // FLAMEDE_CRYPRO_PKCS11_TYPES_CALLBACKS_HPP
