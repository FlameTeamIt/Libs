#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface.hpp>

#include <FlameIDE/Templates/Allocator/ObjectAllocator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{

using namespace flame_ide::pkcs11;

GlobalContext::GlobalContext() noexcept
{
	templates::allocator::ObjectAllocator<structs::FunctionList> allocator;
	structs::FunctionList tmp = {
		oasisVersion
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
	functionList = allocator.construct(tmp);
	if (!functionList)
	{
		status = enums::ReturnType::HOST_MEMORY;
	}
}

GlobalContext::~GlobalContext() noexcept
{
	if (functionList)
	{
		templates::allocator::ObjectAllocator<structs::FunctionList> allocator;
		allocator.destroy(functionList);
	}
}

GlobalContext &GlobalContext::get() noexcept
{
	static GlobalContext globalContext;
	return globalContext;
}

Mutex GlobalContext::createMutex() noexcept
{
	if (enums::value(
			initFlags
			& enums::InitializeArgsFlags::LIBRARY_CANT_CREATE_OS_THREADS
	))
	{
		return Mutex {
				externalCallbacks.create, externalCallbacks.destroy
				, externalCallbacks.lock, externalCallbacks.unlock
		};
	}
	else
	{
		return Mutex{};
	}
}

structs::FunctionListPtr GlobalContext::getFunctionList() noexcept
{
	return functionList;
}

enums::ReturnType GlobalContext::getStatus() const noexcept
{
	return status;
}

}}
