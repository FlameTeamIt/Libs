#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/ObjectFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace object
{

pkcs11::value_types::ReturnType create(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::AttributePtr attributeList
		, pkcs11::value_types::Ulong attributeListLength
		, pkcs11::value_types::ObjectHandlePtr object
)
{
	flame_ide::unused(session);
	flame_ide::unused(attributeList);
	flame_ide::unused(attributeListLength);
	flame_ide::unused(object);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType copy(
		pkcs11::value_types::SessionHandle session
		, CK_OBJECT_HANDLE object
		, pkcs11::structs::AttributePtr attributeList
		, pkcs11::value_types::Ulong attributeListLength
		, pkcs11::value_types::ObjectHandlePtr newObject
)
{
	flame_ide::unused(session);
	flame_ide::unused(object);
	flame_ide::unused(attributeList);
	flame_ide::unused(attributeListLength);
	flame_ide::unused(newObject);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType destroy(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ObjectHandle object
)
{
	flame_ide::unused(session);
	flame_ide::unused(object);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getSize(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ObjectHandle object
		, pkcs11::value_types::UlongPtr resultSize
)
{
	flame_ide::unused(session);
	flame_ide::unused(object);
	flame_ide::unused(resultSize);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getAttributeValue(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ObjectHandle object
		, pkcs11::structs::AttributePtr attributeList
		, pkcs11::value_types::Ulong attributeListLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(object);
	flame_ide::unused(attributeList);
	flame_ide::unused(attributeListLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType setAttributeValue(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ObjectHandle object
		, pkcs11::structs::AttributePtr attributeList
		, pkcs11::value_types::Ulong attributeListLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(object);
	flame_ide::unused(attributeList);
	flame_ide::unused(attributeListLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType findInit(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::AttributePtr attributeList
		, pkcs11::value_types::Ulong attributeListLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(attributeList);
	flame_ide::unused(attributeListLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType find(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ObjectHandlePtr object
		, pkcs11::value_types::Ulong maxObjectCount
		, pkcs11::value_types::UlongPtr objectCount
)
{
	flame_ide::unused(session);
	flame_ide::unused(object);
	flame_ide::unused(maxObjectCount);
	flame_ide::unused(objectCount);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType findFinal(
		pkcs11::value_types::SessionHandle session
)
{
	flame_ide::unused(session);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}


}}}} // flame_ide::soft_pkcs11::functions::object
