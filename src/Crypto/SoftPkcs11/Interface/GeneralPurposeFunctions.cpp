#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/GeneralPurposeFunctions.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_Initialize(CK_VOID_PTR pInitArgs)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.generalPurposeCallbacks
			.initialize(pInitArgs);
}

CK_RV C_Finalize(CK_VOID_PTR pReserved)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.generalPurposeCallbacks
			.finalize(pReserved);
}

CK_RV C_GetInfo(CK_INFO_PTR pInfo)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.generalPurposeCallbacks
			.getInfo(pInfo);
}

CK_RV C_GetFunctionList(CK_FUNCTION_LIST_PTR_PTR ppFunctionList)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.generalPurposeCallbacks
			.getFunctionList(ppFunctionList);
}
