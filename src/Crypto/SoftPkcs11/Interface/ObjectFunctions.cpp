#include <FlameIDE/../../src/Crypto/SoftPkcs11/Interface/ObjectFunctions.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/GlobalContext.hpp>

CK_RV C_CreateObject(
		CK_SESSION_HANDLE hSession
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulCount
		, CK_OBJECT_HANDLE_PTR phObject
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.objectCallbacks
			.create(hSession, pTemplate, ulCount, phObject);
}

CK_RV C_CopyObject(
		CK_SESSION_HANDLE hSession
		, CK_OBJECT_HANDLE hObject
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulCount
		, CK_OBJECT_HANDLE_PTR phNewObject
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.objectCallbacks
			.copy(hSession, hObject, pTemplate, ulCount, phNewObject);
}

CK_RV C_DestroyObject(
		CK_SESSION_HANDLE hSession
		, CK_OBJECT_HANDLE hObject
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.objectCallbacks
			.destroy(hSession, hObject);
}

CK_RV C_GetObjectSize(
		CK_SESSION_HANDLE hSession
		, CK_OBJECT_HANDLE hObject
		, CK_ULONG_PTR pulSize
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.objectCallbacks
			.getSize(hSession, hObject, pulSize);
}

CK_RV C_GetAttributeValue(
		CK_SESSION_HANDLE hSession
		, CK_OBJECT_HANDLE hObject
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulCount
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.objectCallbacks
			.getAttributeValue(hSession, hObject, pTemplate, ulCount);
}

CK_RV C_SetAttributeValue(
		CK_SESSION_HANDLE hSession
		, CK_OBJECT_HANDLE hObject
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulCount
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.objectCallbacks
			.setAttributeValue(hSession, hObject, pTemplate, ulCount);
}

CK_RV C_FindObjectsInit(
		CK_SESSION_HANDLE hSession
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulCount
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.objectCallbacks
			.findInit(hSession, pTemplate, ulCount);
}

CK_RV C_FindObjects(
		CK_SESSION_HANDLE hSession
		, CK_OBJECT_HANDLE_PTR phObject
		, CK_ULONG ulMaxObjectCount
		, CK_ULONG_PTR pulObjectCount
)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.objectCallbacks
			.find(hSession, phObject, ulMaxObjectCount, pulObjectCount);
}

CK_RV C_FindObjectsFinal(CK_SESSION_HANDLE hSession)
{
	return flame_ide::soft_pkcs11::GlobalContext::get()
			.objectCallbacks
			.findFinal(hSession);
}
