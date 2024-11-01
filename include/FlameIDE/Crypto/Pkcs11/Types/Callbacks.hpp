#ifndef FLAMEDE_CRYPTO_PKCS11_TYPES_CALLBACKS_HPP
#define FLAMEDE_CRYPTO_PKCS11_TYPES_CALLBACKS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

namespace flame_ide
{
namespace pkcs11
{
namespace callbacks
{

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_NOTIFICATION event
//           , CK_VOID_PTR pApplication
using Notify = ::CK_NOTIFY;

// CK_RV (*)(CK_VOID_PTR_PTR ppMutex)
using CreateMutex = ::CK_CREATEMUTEX;

// CK_RV (*)(CK_VOID_PTR pMutex)
using DestroyMutex = ::CK_DESTROYMUTEX;

// CK_RV (*)(CK_VOID_PTR pMutex)
using LockMutex = ::CK_LOCKMUTEX;

// CK_RV (*)(CK_VOID_PTR pMutex)
using UnlockMutex = ::CK_UNLOCKMUTEX;


/* General-purpose */

// CK_RV (*)(CK_VOID_PTR pInitArgs)
using Initialize = ::CK_C_Initialize;

// CK_RV (*)(CK_VOID_PTR pReserved)
using Finalize = ::CK_C_Finalize;

// CK_RV (*)(CK_INFO_PTR pInfo)
using GetInfo = ::CK_C_GetInfo;

// CK_RV (*)(CK_FUNCTION_LIST_PTR_PTR ppFunctionList)
using GetFunctionList = ::CK_C_GetFunctionList;


/* Slot and token management */

// CK_RV (*)(CK_BBOOL tokenPresent
//           , CK_SLOT_ID_PTR pSlotList
//           , CK_ULONG_PTR pulCount)
using GetSlotList = ::CK_C_GetSlotList;

// CK_RV (*)(CK_SLOT_ID slotId
//           , CK_SLOT_INFO_PTR pInfo)
using GetSlotInfo = ::CK_C_GetSlotInfo;

// CK_RV (*)(CK_SLOT_ID slotId
//           , CK_TOKEN_INFO_PTR pInfo)
using GetTokenInfo = ::CK_C_GetTokenInfo;

// CK_RV (*)(CK_SLOT_ID slotId
//           , CK_MECHANISM_TYPE_PTR pMechanismList
//           , CK_ULONG_PTR pulCount)
using GetMechanismList = ::CK_C_GetMechanismList;

// CK_RV (*)(CK_SLOT_ID slotId
//           , CK_MECHANISM_TYPE type
//           , CK_MECHANISM_INFO_PTR pInfo)
using GetMechanismInfo = ::CK_C_GetMechanismInfo;

// CK_RV (*)(CK_SLOT_ID slotId
//           , CK_UTF8CHAR_PTR pPin
//           , CK_ULONG ulPinLen
//           , CK_UTF8CHAR_PTR pLabel)
using InitToken = ::CK_C_InitToken;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_UTF8CHAR_PTR pPin
//           , CK_ULONG ulPinLen)
using InitPin = ::CK_C_InitPIN;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_UTF8CHAR_PTR pOldPin
//           , CK_ULONG ulOldLen
//           , CK_UTF8CHAR_PTR pMewPin
//           , CK_ULONG ulNewLen)
using SetPin = ::CK_C_SetPIN;


/* Session management */

// CK_RV (*)(CK_SLOT_ID slotId
//           , CK_FLAGS flags
//           , CK_VOID_PTR pApplication
//           , CK_NOTIFY Notify
//           , CK_SESSION_HANDLE_PTR phSession)
using OpenSession = ::CK_C_OpenSession;

// CK_RV (*)(CK_SESSION_HANDLE hSession)
using CloseSession = ::CK_C_CloseSession;

// CK_RV (*)(CK_SLOT_ID slotId)
using CloseAllSessions = ::CK_C_CloseAllSessions;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//, CK_SESSION_INFO_PTR pInfo)
using GetSessionInfo = ::CK_C_GetSessionInfo;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//, CK_BYTE_PTR pOperationState
//, CK_ULONG_PTR pulOperationStateLen)
using GetOperationState = ::CK_C_GetOperationState;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pOperationState
//           , CK_ULONG ulOperationStateLen
//           , CK_OBJECT_HANDLE hEncryptionKey
//           , CK_OBJECT_HANDLE hAuthenticationKey)
using SetOperationState = ::CK_C_SetOperationState;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_USER_TYPE userType
//           , CK_UTF8CHAR_PTR pPin
//           , CK_ULONG ulPinLen)
using Login = ::CK_C_Login;

// CK_RV (*)(CK_SESSION_HANDLE hSession)
using Logout = ::CK_C_Logout;


/* Object management */

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_ATTRIBUTE_PTR pTemplate
//           , CK_ULONG ulCount
//           , CK_OBJECT_HANDLE_PTR phObject)
using CreateObject = ::CK_C_CreateObject;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_OBJECT_HANDLE hObject
//           , CK_ATTRIBUTE_PTR pTemplate
//           , CK_ULONG ulCount
//           , CK_OBJECT_HANDLE_PTR phNewObject)
using CopyObject = ::CK_C_CopyObject;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_OBJECT_HANDLE hObject)
using DestroyObject = ::CK_C_DestroyObject;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_OBJECT_HANDLE hObject
//           , CK_ULONG_PTR pulSize)
using GetObjectSize = ::CK_C_GetObjectSize;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_OBJECT_HANDLE hObject
//           , CK_ATTRIBUTE_PTR pTemplate
//           , CK_ULONG ulCount)
using GetAttributeValue = ::CK_C_GetAttributeValue;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_OBJECT_HANDLE hObject
//           , CK_ATTRIBUTE_PTR pTemplate
//           , CK_ULONG ulCount)
using SetAttributeValue = ::CK_C_SetAttributeValue;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_ATTRIBUTE_PTR pTemplate
//           , CK_ULONG ulCount)
using FindObjectsInit = ::CK_C_FindObjectsInit;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_OBJECT_HANDLE_PTR phObject
//           , CK_ULONG ulMaxObjectCount
//           , CK_ULONG_PTR pulObjectCount)
using FindObjects = ::CK_C_FindObjects;

// CK_RV (*)(CK_SESSION_HANDLE hSession)
using FindObjectsFinal = ::CK_C_FindObjectsFinal;


/* Encryption */

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_MECHANISM_PTR pMechanism
//           , CK_OBJECT_HANDLE hKey)
using EncryptInit = ::CK_C_EncryptInit;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pData
//           , CK_ULONG ulDataLen
//           , CK_BYTE_PTR pEncryptedData
//           , CK_ULONG_PTR pulEncryptedDataLen)
using Encrypt = ::CK_C_Encrypt;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pPart
//           , CK_ULONG ulPartLen
//           , CK_BYTE_PTR pEncryptedPart
//           , CK_ULONG_PTR pulEncryptedPartLen)
using EncryptUpdate = ::CK_C_EncryptUpdate;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pLastEncryptedPart
//           , CK_ULONG_PTR pulLastEncryptedPartLen)
using EncryptFinal = ::CK_C_EncryptFinal;


/* Decryption */

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_MECHANISM_PTR pMechanism
//           , CK_OBJECT_HANDLE hKey)
using DecryptInit = ::CK_C_DecryptInit;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pEncryptedData
//           , CK_ULONG ulEncryptedDataLen
//           , CK_BYTE_PTR pData
//           , CK_ULONG_PTR pulDataLen)
using Decrypt = ::CK_C_Decrypt;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pEncryptedPart
//           , CK_ULONG ulEncryptedPartLen
//           , CK_BYTE_PTR pPart
//           , CK_ULONG_PTR pulPartLen)
using DecryptUpdate = ::CK_C_DecryptUpdate;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pLastPart
//           , CK_ULONG_PTR pulLastPartLen)
using DecryptFinal = ::CK_C_DecryptFinal;


/* Message digesting */

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_MECHANISM_PTR pMechanism)
using DigestInit = ::CK_C_DigestInit;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pData
//           , CK_ULONG ulDataLen
//           , CK_BYTE_PTR pDigest
//           , CK_ULONG_PTR pulDigestLen)
using Digest = ::CK_C_Digest;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pPart
//           , CK_ULONG ulPartLen)
using DigestUpdate = ::CK_C_DigestUpdate;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_OBJECT_HANDLE hKey)
using DigestKey = ::CK_C_DigestKey;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pDigest
//           , CK_ULONG_PTR pulDigestLen)
using DigestFinal = ::CK_C_DigestFinal;


/* Signing and MACing */

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_MECHANISM_PTR pMechanism
//           , CK_OBJECT_HANDLE hKey)
using SignInit = ::CK_C_SignInit;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pData
//           , CK_ULONG ulDataLen
//           , CK_BYTE_PTR pSignature
//           , CK_ULONG_PTR pulSignatureLen)
using Sign = ::CK_C_Sign;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pPart
//           , CK_ULONG ulPartLen)
using SignUpdate = ::CK_C_SignUpdate;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pSignature
//           , CK_ULONG_PTR pulSignatureLen)
using SignFinal = ::CK_C_SignFinal;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//          , CK_MECHANISM_PTR pMechanism
//          , CK_OBJECT_HANDLE hKey)
using SignRecoverInit = ::CK_C_SignRecoverInit;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pData
//           , CK_ULONG ulDataLen
//           , CK_BYTE_PTR pSignature
//           , CK_ULONG_PTR pulSignatureLen)
using SignRecover = ::CK_C_SignRecover;


/* Verifying signatures and MACs */

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_MECHANISM_PTR pMechanism
//           , CK_OBJECT_HANDLE hKey)
using VerifyInit = ::CK_C_VerifyInit;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pData
//           , CK_ULONG ulDataLen
//           , CK_BYTE_PTR pSignature
//           , CK_ULONG ulSignatureLen)
using Verify = ::CK_C_Verify;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pPart
//           , CK_ULONG ulPartLen)
using VerifyUpdate = ::CK_C_VerifyUpdate;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pSignature
//           , CK_ULONG ulSignatureLen)
using VerifyFinal = ::CK_C_VerifyFinal;

//CK_RV (*)(CK_SESSION_HANDLE hSession
//          , CK_MECHANISM_PTR pMechanism
//          , CK_OBJECT_HANDLE hKey)
using VerifyRecoverInit = ::CK_C_VerifyRecoverInit;

//CK_RV (*)(CK_SESSION_HANDLE hSession
//          , CK_BYTE_PTR pSignature
//          , CK_ULONG ulSignatureLen
//          , CK_BYTE_PTR pData
//          , CK_ULONG_PTR pulDataLen)
using VerifyRecover = ::CK_C_VerifyRecover;


/* Dual-function cryptographic operations */

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pPart
//           , CK_ULONG ulPartLen
//           , CK_BYTE_PTR pEncryptedPart
//           , CK_ULONG_PTR pulEncryptedPartLen)
using DigestEncryptUpdate = ::CK_C_DigestEncryptUpdate;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//          , CK_BYTE_PTR pEncryptedPart
//          , CK_ULONG ulEncryptedPartLen
//          , CK_BYTE_PTR pPart
//          , CK_ULONG_PTR pulPartLen)
using DecryptDigestUpdate = ::CK_C_DecryptDigestUpdate;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//          , CK_BYTE_PTR pPart
//          , CK_ULONG ulPartLen
//          , CK_BYTE_PTR pEncryptedPart
//          , CK_ULONG_PTR pulEncryptedPartLen)
using SignEncryptUpdate = ::CK_C_SignEncryptUpdate;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pEncryptedPart
//           , CK_ULONG ulEncryptedPartLen
//           , CK_BYTE_PTR pPart
//           , CK_ULONG_PTR pulPartLen)
using DecryptVerifyUpdate = ::CK_C_DecryptVerifyUpdate;


/* Key management */

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_MECHANISM_PTR pMechanism
//           , CK_ATTRIBUTE_PTR pTemplate
//           , CK_ULONG ulCount
//           , CK_OBJECT_HANDLE_PTR phKey)
using GenerateKey = ::CK_C_GenerateKey;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_MECHANISM_PTR pMechanism
//           , CK_ATTRIBUTE_PTR pPublicKeyTemplate
//           , CK_ULONG ulPublicKeyAttributeCount
//           , CK_ATTRIBUTE_PTR pPrivateKeyTemplate
//           , CK_ULONG ulPrivateKeyAttributeCount
//           , CK_OBJECT_HANDLE_PTR phPublicKey
//           , CK_OBJECT_HANDLE_PTR phPrivateKey)
using GenerateKeyPair = ::CK_C_GenerateKeyPair;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_MECHANISM_PTR pMechanism
//           , CK_OBJECT_HANDLE hWrappingKey
//           , CK_OBJECT_HANDLE hKey
//           , CK_BYTE_PTR pWrappedKey
//           , CK_ULONG_PTR pulWrappedKeyLen)
using WrapKey = ::CK_C_WrapKey;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_MECHANISM_PTR pMechanism
//           , CK_OBJECT_HANDLE hUnwrappingKey
//           , CK_BYTE_PTR pWrappedKey
//           , CK_ULONG ulWrappedKeyLen
//           , CK_ATTRIBUTE_PTR pTemplate
//           , CK_ULONG ulAttributeCount
//           , CK_OBJECT_HANDLE_PTR phKey)
using UnwrapKey = ::CK_C_UnwrapKey;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_MECHANISM_PTR pMechanism
//           , CK_OBJECT_HANDLE hBaseKey
//           , CK_ATTRIBUTE_PTR pTemplate
//           , CK_ULONG ulAttributeCount
//           , CK_OBJECT_HANDLE_PTR phKey)
using DeriveKey = ::CK_C_DeriveKey;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR pSeed
//           , CK_ULONG ulSeedLen)
using SeedRandom = ::CK_C_SeedRandom;

// CK_RV (*)(CK_SESSION_HANDLE hSession
//           , CK_BYTE_PTR RandomData
//           , CK_ULONG ulRandomLen)
using GenerateRandom = ::CK_C_GenerateRandom;


/* Parallel function management */

// CK_RV (*)(CK_SESSION_HANDLE hSession)
using GetFunctionStatus = ::CK_C_GetFunctionStatus;

// CK_RV (*)(CK_SESSION_HANDLE hSession)
using CancelFunction = ::CK_C_CancelFunction;

// CK_RV (*)(CK_FLAGS flags
//           , CK_SLOT_ID_PTR pSlot
//           , CK_VOID_PTR pRserved)
using WaitForSlotEvent = ::CK_C_WaitForSlotEvent;


/* v3.0 */

// CK_RV(*)(CK_INTERFACE_PTR pInterfacesList
//         , CK_ULONG_PTR pulCount)
using GetInterfaceList = ::CK_C_GetInterfaceList;

// CR_RV(*)(CK_UTF8CHAR_PTR pInterfaceName
//          , CK_VERSION_PTR pVersion
//          , CK_INTERFACE_PTR_PTR ppInterface
//          , CK_FLAGS flags)
using GetInterface = ::CK_C_GetInterface;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_USER_TYPE userType
//          , CK_UTF8CHAR_PTR pPin
//          , CK_ULONG ulPinLen
//          , CK_UTF8CHAR_PTR pUsername
//          , CK_ULONG ulUsernameLen)
using LoginUser = ::CK_C_LoginUser;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_FLAGS flags)
using SessionCancel = ::CK_C_SessionCancel;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_MECHANISM_PTR pMechanism
//          , CK_OBJECT_HANDLE hKey)
using MessageEncryptInit = ::CK_C_MessageEncryptInit;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_VOID_PTR pParameter
//          , CK_ULONG ulParameterLen
//          , CK_BYTE_PTR pAssociatedData
//          , CK_ULONG ulAssociatedDataLen
//          , CK_BYTE_PTR pPlaintext
//          , CK_ULONG ulPlaintextLen
//          , CK_BYTE_PTR pCiphertext
//          , CK_ULONG_PTR pulCiphertextLen)
using EncryptMessage = ::CK_C_EncryptMessage;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_VOID_PTR pParameter
//          , CK_ULONG ulParameterLen
//          , CK_BYTE_PTR pAssociatedData
//          , CK_ULONG ulAssociatedDataLen)
using EncryptMessageBegin = ::CK_C_EncryptMessageBegin;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_VOID_PTR pParameter
//          , CK_ULONG ulParameterLen
//          , CK_BYTE_PTR pPlaintextPart
//          , CK_ULONG ulPlaintextPartLen
//          , CK_BYTE_PTR pCiphertextPart
//          , CK_ULONG_PTR pulCiphertextPartLen
//          , CK_FLAGS flags)
using EncryptMessageNext = ::CK_C_EncryptMessageNext;

// CK_RV(*)(CK_SESSION_HANDLE hSession)
using EncryptMessageFinal = ::CK_C_MessageEncryptFinal;

//CK_RV(*)(CK_SESSION_HANDLE hSession
//         , CK_MECHANISM_PTR pMechanism
//         , CK_OBJECT_HANDLE hKey)
using MessageDecryptInit = ::CK_C_MessageDecryptInit;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_VOID_PTR pParameter
//          , CK_ULONG ulParameterLen
//          , CK_BYTE_PTR pAssociatedData
//          , CK_ULONG ulAssociatedDataLen
//          , CK_BYTE_PTR pCiphertext
//          , CK_ULONG ulCiphertextLen
//          , CK_BYTE_PTR pPlaintext
//          , CK_ULONG_PTR pulPlaintextLen)
using DecryptMessage = ::CK_C_DecryptMessage;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_VOID_PTR pParameter
//          , CK_ULONG ulParameterLen
//          , CK_BYTE_PTR pAssociatedData
//          , CK_ULONG ulAssociatedDataLen)
using DecryptMessageBegin = ::CK_C_DecryptMessageBegin;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_VOID_PTR pParameter
//          , CK_ULONG ulParameterLen
//          , CK_BYTE_PTR pCiphertext
//          , CK_ULONG ulCiphertextLen
//          , CK_BYTE_PTR pPlaintext
//          , CK_ULONG_PTR pulPlaintextLen
//          , CK_FLAGS flags)
using DecryptMessageNext = ::CK_C_DecryptMessageNext;

// CK_RV(*)(CK_SESSION_HANDLE hSession)
using MessageDecryptFinal = ::CK_C_MessageDecryptFinal;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_MECHANISM_PTR  pMechanism
//          , CK_OBJECT_HANDLE  hKey)
using MessageSignInit = ::CK_C_MessageSignInit;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_VOID_PTR pParameter
//          , CK_ULONG ulParameterLen
//          , CK_BYTE_PTR pData
//          , CK_ULONG ulDataLen
//          , CK_BYTE_PTR pSignature
//          , CK_ULONG_PTR pulSignatureLen)
using SignMessage = ::CK_C_SignMessage;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_VOID_PTR pParameter
//          , CK_ULONG ulParameterLen)
using SignMessageBegin = ::CK_C_SignMessageBegin;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_VOID_PTR pParameter
//          , CK_ULONG ulParameterLen
//          , CK_BYTE_PTR pData
//          , CK_ULONG ulDataLen
//          , CK_BYTE_PTR pSignature
//          , CK_ULONG_PTR pulSignatureLen)
using SignMessageNext = ::CK_C_SignMessageNext;

// CK_RV(*)(CK_SESSION_HANDLE hSession)
using MessageSignFinal = ::CK_C_MessageSignFinal;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_MECHANISM_PTR  pMechanism
//          , CK_OBJECT_HANDLE  hKey)
using MessageVerifyInit = ::CK_C_MessageVerifyInit;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_VOID_PTR pParameter
//          , CK_ULONG ulParameterLen
//          , CK_BYTE_PTR pData
//          , CK_ULONG ulDataLen
//          , CK_BYTE_PTR pSignature
//          , CK_ULONG ulSignatureLen)
using VerifyMessage = ::CK_C_VerifyMessage;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_VOID_PTR pParameter
//          , CK_ULONG ulParameterLen)
using VerifyMessageBegin = ::CK_C_VerifyMessageBegin;

// CK_RV(*)(CK_SESSION_HANDLE hSession
//          , CK_VOID_PTR pParameter
//          , CK_ULONG ulParameterLen
//          , CK_BYTE_PTR pData
//          , CK_ULONG ulDataLen
//          , CK_BYTE_PTR pSignature
//          , CK_ULONG ulSignatureLen)
using VerifyMessageNext = ::CK_C_VerifyMessageNext;

// CK_RV(*)(CK_SESSION_HANDLE hSession)
using MessageVerifyFinal = ::CK_C_MessageVerifyFinal;

namespace names
{

constexpr char Initialize[] = "C_Initialize";
constexpr char Finalize[] = "C_Finalize";
constexpr char GetInfo[] = "C_GetInfo";
constexpr char GetFunctionList[] = "C_GetFunctionList";
constexpr char GetSlotList[] = "C_GetSlotList";
constexpr char GetSlotInfo[] = "C_GetSlotInfo";
constexpr char GetMechanismList[] = "C_GetMechanismList";
constexpr char GetMechanismInfo[] = "C_GetMechanismInfo";
constexpr char InitPin[] = "C_InitPIN";
constexpr char SetPin[] = "C_SetPIN";
constexpr char OpenSession[] = "C_OpenSession";
constexpr char CloseSession[] = "C_CloseSession";
constexpr char CloseAllSessions[] = "C_CloseAllSessions";
constexpr char GetSessionInfo[] = "C_GetSessionInfo";
constexpr char GetOperationState[] = "C_GetOperationState";
constexpr char SetOperationState[] = "C_SetOperationState";
constexpr char Login[] = "C_Login";
constexpr char Logout[] = "C_Logout";
constexpr char CreateObject[] = "C_CreateObject";
constexpr char CopyObject[] = "C_CopyObject";
constexpr char DestroyObject[] = "C_DestroyObject";
constexpr char GetObjectSize[] = "C_GetObjectSize";
constexpr char GetAttributeValue[] = "C_GetAttributeValue";
constexpr char SetAttributeValue[] = "C_SetAttributeValue";
constexpr char FindObjectsInit[] = "C_FindObjectsInit";
constexpr char FindObjects[] = "C_FindObjects";
constexpr char FindObjectsFinal[] = "C_FindObjectsFinal";
constexpr char EncryptInit[] = "C_EncryptInit";
constexpr char Encrypt[] = "C_Encrypt";
constexpr char EncryptUpdate[] = "C_EncryptUpdate";
constexpr char EncryptFinal[] = "C_EncryptFinal";
constexpr char DecryptInit[] = "C_DecryptInit";
constexpr char Decrypt[] = "C_Decrypt";
constexpr char DecryptUpdate[] = "C_DecryptUpdate";
constexpr char DecryptFinal[] = "C_DecryptFinal";
constexpr char DigestInit[] = "C_DigestInit";
constexpr char Digest[] = "C_Digest";
constexpr char DigestUpdate[] = "C_DigestUpdate";
constexpr char DigestKey[] = "C_DigestKey";
constexpr char DigestFinal[] = "C_DigestFinal";
constexpr char SignInit[] = "C_SignInit";
constexpr char Sign[] = "C_Sign";
constexpr char SignUpdate[] = "C_SignUpdate";
constexpr char SignFinal[] = "C_SignFinal";
constexpr char SignRecoverInit[] = "C_SignRecoverInit";
constexpr char SignRecover[] = "C_SignRecover";
constexpr char VerifyInit[] = "C_VerifyInit";
constexpr char Verify[] = "C_Verify";
constexpr char VerifyUpdate[] = "C_VerifyUpdate";
constexpr char VerifyFinal[] = "C_VerifyFinal";
constexpr char VerifyRecoverInit[] = "C_VerifyRecoverInit";
constexpr char VerifyRecover[] = "C_VerifyRecover";
constexpr char DigestEncryptUpdate[] = "C_DigestEncryptUpdate";
constexpr char DecryptDigestUpdate[] = "C_DecryptDigestUpdate";
constexpr char SignEncryptUpdate[] = "C_SignEncryptUpdate";
constexpr char DecryptVerifyUpdate[] = "C_DecryptVerifyUpdate";
constexpr char GenerateKey[] = "C_GenerateKey";
constexpr char GenerateKeyPair[] = "C_GenerateKeyPair";
constexpr char WrapKey[] = "C_WrapKey";
constexpr char UnwrapKey[] = "C_UnwrapKey";
constexpr char DeriveKey[] = "C_DeriveKey";
constexpr char SeedRandom[] = "C_SeedRandom";
constexpr char GenerateRandom[] = "C_GenerateRandom";
constexpr char GetFunctionStatus[] = "C_GetFunctionStatus";
constexpr char CancelFunction[] = "C_CancelFunction";
constexpr char WaitForSlotEvent[] = "C_WaitForSlotEvent";

// v3.0

constexpr char GetInterfaceList[] = "C_GetInterfaceList";
constexpr char GetInterface[] = "C_GetInterface";
constexpr char LoginUser[] = "C_LoginUser";
constexpr char SessionCancel[] = "C_SessionCancel";
constexpr char MessageEncryptInit[] = "C_MessageEncryptInit";
constexpr char EncryptMessage[] = "C_EncryptMessage";
constexpr char EncryptMessageBegin[] = "C_EncryptMessageBegin";
constexpr char EncryptMessageNext[] = "C_EncryptMessageNext";
constexpr char EncryptMessageFinal[] = "C_MessageEncryptFinal";
constexpr char MessageDecryptInit[] = "C_MessageDecryptInit";
constexpr char DecryptMessage[] = "C_DecryptMessage";
constexpr char DecryptMessageBegin[] = "C_DecryptMessageBegin";
constexpr char DecryptMessageNext[] = "C_DecryptMessageNext";
constexpr char MessageDecryptFinal[] = "C_MessageDecryptFinal";
constexpr char MessageSignInit[] = "C_MessageSignInit";
constexpr char SignMessage[] = "C_SignMessage";
constexpr char SignMessageBegin[] = "C_SignMessageBegin";
constexpr char SignMessageNext[] = "C_SignMessageNext";
constexpr char MessageSignFinal[] = "C_MessageSignFinal";
constexpr char MessageVerifyInit[] = "C_MessageVerifyInit";
constexpr char VerifyMessage[] = "C_VerifyMessage";
constexpr char VerifyMessageBegin[] = "C_VerifyMessageBegin";
constexpr char VerifyMessageNext[] = "C_VerifyMessageNext";
constexpr char MessageVerifyFinal[] = "C_MessageVerifyFinal";

} // namespace names

} // namespace callbacks
} // namespace pkcs11
} // namespace flame_ide

#endif // FLAMEDE_CRYPTO_PKCS11_TYPES_CALLBACKS_HPP
