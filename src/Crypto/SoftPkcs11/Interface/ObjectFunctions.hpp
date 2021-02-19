#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_OBJECTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_OBJECTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// \brief C_CreateObject
/// \param hSession
/// \param pTemplate
/// \param ulCount
/// \param phObject
/// \return
///
CK_RV C_CreateObject(
		CK_SESSION_HANDLE hSession
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulCount
		, CK_OBJECT_HANDLE_PTR phObject
);

///
/// \brief C_CopyObject
/// \param hSession
/// \param hObject
/// \param pTemplate
/// \param ulCount
/// \param phNewObject
/// \return
///
CK_RV C_CopyObject(
		CK_SESSION_HANDLE hSession
		, CK_OBJECT_HANDLE hObject
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulCount
		, CK_OBJECT_HANDLE_PTR phNewObject
);

///
/// \brief C_DestroyObject
/// \param hSession
/// \param hObject
/// \return
///
CK_RV C_DestroyObject(
		CK_SESSION_HANDLE hSession
		, CK_OBJECT_HANDLE hObject
);

///
/// \brief C_GetObjectSize
/// \param hSession
/// \param hObject
/// \param pulSize
/// \return
///
CK_RV C_GetObjectSize(
		CK_SESSION_HANDLE hSession
		, CK_OBJECT_HANDLE hObject
		, CK_ULONG_PTR pulSize
);

///
/// \brief C_GetAttributeValue
/// \param hSession
/// \param hObject
/// \param pTemplate
/// \param ulCount
/// \return
///
CK_RV C_GetAttributeValue(
		CK_SESSION_HANDLE hSession
		, CK_OBJECT_HANDLE hObject
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulCount
);

///
/// \brief C_SetAttributeValue
/// \param hSession
/// \param hObject
/// \param pTemplate
/// \param ulCount
/// \return
///
CK_RV C_SetAttributeValue(
		CK_SESSION_HANDLE hSession
		, CK_OBJECT_HANDLE hObject
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulCount
);

///
/// \brief C_FindObjectsInit
/// \param hSession
/// \param pTemplate
/// \param ulCount
/// \return
///
CK_RV C_FindObjectsInit(
		CK_SESSION_HANDLE hSession
		, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulCount
);

///
/// \brief C_FindObjects
/// \param hSession
/// \param phObject
/// \param ulMaxObjectCount
/// \param pulObjectCount
/// \return
///
CK_RV C_FindObjects(
		CK_SESSION_HANDLE hSession
		, CK_OBJECT_HANDLE_PTR phObject
		, CK_ULONG ulMaxObjectCount
		, CK_ULONG_PTR pulObjectCount
);

CK_RV C_FindObjectsFinal(CK_SESSION_HANDLE hSession);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_OBJECTFUNCTIONS_HPP
