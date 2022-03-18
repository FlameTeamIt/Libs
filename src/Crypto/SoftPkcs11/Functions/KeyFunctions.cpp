#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/KeyFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace key
{

pkcs11::value_types::ReturnType generateKey(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::structs::AttributePtr attributeList
		, pkcs11::value_types::Ulong attributeListLength
		, pkcs11::value_types::ObjectHandlePtr key
)
{
	flame_ide::unused(session);
	flame_ide::unused(mechanism);
	flame_ide::unused(attributeList);
	flame_ide::unused(attributeListLength);
	flame_ide::unused(key);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType generateKeyPair(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::structs::AttributePtr publicKeyAttrbuteList
		, pkcs11::value_types::Ulong publicKeyAttributeListLength
		, pkcs11::structs::AttributePtr privateKeyTemplate
		, pkcs11::value_types::Ulong privateKeyAttributeCount
		, pkcs11::value_types::ObjectHandlePtr publicKey
		, pkcs11::value_types::ObjectHandlePtr privateKey
)
{
	flame_ide::unused(session);
	flame_ide::unused(mechanism);
	flame_ide::unused(publicKeyAttrbuteList);
	flame_ide::unused(publicKeyAttributeListLength);
	flame_ide::unused(privateKeyTemplate);
	flame_ide::unused(privateKeyAttributeCount);
	flame_ide::unused(publicKey);
	flame_ide::unused(privateKey);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType wrapKey(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::value_types::ObjectHandle hWrappingKey
		, pkcs11::value_types::ObjectHandle hKey
		, pkcs11::value_types::BytePtr pWrappedKey
		, pkcs11::value_types::UlongPtr pulWrappedKeyLen
)
{
	flame_ide::unused(session);
	flame_ide::unused(mechanism);
	flame_ide::unused(hWrappingKey);
	flame_ide::unused(hKey);
	flame_ide::unused(pWrappedKey);
	flame_ide::unused(pulWrappedKeyLen);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType unwrapKey(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::value_types::ObjectHandle unwrappingKey
		, pkcs11::value_types::BytePtr wrappedKey
		, pkcs11::value_types::Ulong wrappedKeyLength
		, pkcs11::structs::AttributePtr pTemplate
		, pkcs11::value_types::Ulong ulAttributeCount
		, pkcs11::value_types::ObjectHandlePtr phKey
)
{
	flame_ide::unused(session);
	flame_ide::unused(mechanism);
	flame_ide::unused(unwrappingKey);
	flame_ide::unused(wrappedKey);
	flame_ide::unused(wrappedKeyLength);
	flame_ide::unused(pTemplate);
	flame_ide::unused(ulAttributeCount);
	flame_ide::unused(phKey);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType deriveKey(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::value_types::ObjectHandle baseKey
		, pkcs11::structs::AttributePtr attributeList
		, pkcs11::value_types::Ulong attributeListLength
		, pkcs11::value_types::ObjectHandlePtr key
)
{
	flame_ide::unused(session);
	flame_ide::unused(mechanism);
	flame_ide::unused(baseKey);
	flame_ide::unused(attributeList);
	flame_ide::unused(attributeListLength);
	flame_ide::unused(key);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::key
