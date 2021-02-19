#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_OBJECTFUNCTIONS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_OBJECTFUNCTIONS_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace object
{

///
/// \brief create
/// \param session
/// \param attributeList
/// \param attributeListLength
/// \param object
/// \return
///
pkcs11::value_types::ReturnType create(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::AttributePtr attributeList
		, pkcs11::value_types::Ulong attributeListLength
		, pkcs11::value_types::ObjectHandlePtr object
);

///
/// \brief copy
/// \param session
/// \param object
/// \param attributeList
/// \param attributeListLength
/// \param newObject
/// \return
///
pkcs11::value_types::ReturnType copy(
		pkcs11::value_types::SessionHandle session
		, CK_OBJECT_HANDLE object
		, pkcs11::structs::AttributePtr attributeList
		, pkcs11::value_types::Ulong attributeListLength
		, pkcs11::value_types::ObjectHandlePtr newObject
);

///
/// \brief destroy
/// \param session
/// \param object
/// \return
///
pkcs11::value_types::ReturnType destroy(
		pkcs11::value_types::SessionHandle session
		, CK_OBJECT_HANDLE object
);

///
/// \brief getSize
/// \param session
/// \param object
/// \param pulSize
/// \return
///
pkcs11::value_types::ReturnType getSize(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ObjectHandle object
		, pkcs11::value_types::UlongPtr pulSize
);

///
/// \brief getAttributeValue
/// \param session
/// \param object
/// \param attributeList
/// \param attributeListLength
/// \return
///
pkcs11::value_types::ReturnType getAttributeValue(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ObjectHandle object
		, pkcs11::structs::AttributePtr attributeList
		, pkcs11::value_types::Ulong attributeListLength
);

///
/// \brief setAttributeValue
/// \param session
/// \param object
/// \param attributeList
/// \param attributeListLength
/// \return
///
pkcs11::value_types::ReturnType setAttributeValue(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ObjectHandle object
		, pkcs11::structs::AttributePtr attributeList
		, pkcs11::value_types::Ulong attributeListLength
);

///
/// \brief findInit
/// \param session
/// \param attributeList
/// \param attributeListLength
/// \return
///
pkcs11::value_types::ReturnType findInit(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::AttributePtr attributeList
		, pkcs11::value_types::Ulong attributeListLength
);

///
/// \brief find
/// \param session
/// \param object
/// \param maxObjectCount
/// \param objectCount
/// \return
///
pkcs11::value_types::ReturnType find(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ObjectHandlePtr object
		, pkcs11::value_types::Ulong maxObjectCount
		, pkcs11::value_types::UlongPtr objectCount
);

///
/// \brief findFinal
/// \param session
/// \return
///
pkcs11::value_types::ReturnType findFinal(
		pkcs11::value_types::SessionHandle session
);

}}}} // flame_ide::soft_pkcs11::functions::object

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_FUNCTIONS_OBJECTFUNCTIONS_HPP
