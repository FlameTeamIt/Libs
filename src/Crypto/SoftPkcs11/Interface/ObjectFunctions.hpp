#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_OBJECTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_OBJECTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Oasis/Oasis.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

///
/// @brief Creates a new object
/// @param[in] hSession The session's handle
/// @param[in] pTemplate The object's template
/// @param[in] ulCount Attributes in template
/// @param[out] phObject Gets new object's handle
/// @return See CKR_* values
///
CK_RV C_CreateObject(CK_SESSION_HANDLE hSession, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulCount, CK_OBJECT_HANDLE_PTR phObject);

///
/// @brief Copies an object, creating a new object for the copy
/// @param[in] hSession The session's handle
/// @param[in] hObject The object's handle
/// @param[in] pTemplate Template for new object
/// @param[in] ulCount Attributes in template
/// @param[out] phNewObject Receives handle of copy
/// @return See CKR_* values
///
CK_RV C_CopyObject(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hObject
		, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount
		, CK_OBJECT_HANDLE_PTR phNewObject);

///
/// @brief Destroys an object
/// @param[in] hSession The session's handle
/// @param[in] hObject The object's handle
/// @return See CKR_* values
///
CK_RV C_DestroyObject(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hObject);

///
/// @brief Gets the size of an object in bytes
/// @param[in] hSession The session's handle
/// @param[in] hObject The object's handle
/// @param[out] pulSize Receives size of object
/// @return See CKR_* values
///
CK_RV C_GetObjectSize(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hObject
		, CK_ULONG_PTR pulSize);

///
/// @brief Obtains the value of one or more object attributes
/// @param[in] hSession The session's handle
/// @param[in] hObject The object's handle
/// @param[out] pTemplate Specifies attrs; gets
/// @param[in] ulCount Attributes in template
/// @return See CKR_* values
///
CK_RV C_GetAttributeValue(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hObject
		, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount);

///
/// @brief Modifies the value of one or more object attributes
/// @param[in] hSession The session's handle
/// @param[in] hObject The object's handle
/// @param[in] pTemplate Specifies attrs and values
/// @param[in] ulCount Attributes in template
/// @return See CKR_* values
///
CK_RV C_SetAttributeValue(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hObject
		, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount);

///
/// @brief initializes a search for token and session objects that match a template
/// @param[in] hSession The session's handle
/// @param[in] pTemplate Attribute values to match
/// @param[in] ulCount Attrs in search template
/// @return See CKR_* values
///
CK_RV C_FindObjectsInit(CK_SESSION_HANDLE hSession, CK_ATTRIBUTE_PTR pTemplate
		, CK_ULONG ulCount);

///
/// @brief Continues a search for token and session objects that match a template,
/// obtaining additional object handles
/// @param[in] hSession Session's handle
/// @param[out] phObject Gets object handles
/// @param[in] ulMaxObjectCount Max handles to get
/// @param[out] pulObjectCount Actual count returned
/// @return See CKR_* values
///
CK_RV C_FindObjects(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE_PTR phObject
		, CK_ULONG ulMaxObjectCount, CK_ULONG_PTR pulObjectCount);

///
/// @brief Finishes a search for token and session objects
/// @param[in] hSession The session's handle
/// @return See CKR_* values
///
CK_RV C_FindObjectsFinal(CK_SESSION_HANDLE hSession);

#ifdef __cplusplus
}
#endif

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_INTERFACE_OBJECTFUNCTIONS_HPP
