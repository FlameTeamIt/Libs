#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/ParallelManagementFunctions.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_GetFunctionStatus(CK_SESSION_HANDLE hSession)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.parallelManagement
			.getFunctionStatus(hSession);
}

CK_RV C_CancelFunction(CK_SESSION_HANDLE hSession)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.parallelManagement
			.cancelfunciton(hSession);
}

CK_RV C_WaitForSlotEvent(
		CK_FLAGS flags
		, CK_SLOT_ID_PTR pSlot
		, CK_VOID_PTR pReserved
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.callbacks()
			.parallelManagement
			.waitForSlotEvent(flags, pSlot, pReserved);
}
