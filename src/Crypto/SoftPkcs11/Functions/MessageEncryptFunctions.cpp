#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/MessageEncryptFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace message
{

pkcs11::value_types::ReturnType encryptInit(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::value_types::ObjectHandle key
)
{
	flame_ide::unused(session);
	flame_ide::unused(mechanism);
	flame_ide::unused(key);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType encrypt(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ValuePtr parameter
		, pkcs11::value_types::Ulong parameterLength
		, pkcs11::value_types::BytePtr associatedData
		, pkcs11::value_types::Ulong associatedDataLength
		, pkcs11::value_types::BytePtr plainText
		, pkcs11::value_types::Ulong plainTextLength
		, pkcs11::value_types::BytePtr cipherText
		, pkcs11::value_types::UlongPtr cipherTextLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(parameter);
	flame_ide::unused(parameterLength);
	flame_ide::unused(associatedData);
	flame_ide::unused(associatedDataLength);
	flame_ide::unused(plainText);
	flame_ide::unused(plainTextLength);
	flame_ide::unused(cipherText);
	flame_ide::unused(cipherTextLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType encryptBegin(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ValuePtr parameter
		, pkcs11::value_types::Ulong parameterLength
		, pkcs11::value_types::BytePtr associatedData
		, pkcs11::value_types::Ulong associatedDataLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(parameter);
	flame_ide::unused(parameterLength);
	flame_ide::unused(associatedData);
	flame_ide::unused(associatedDataLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType encryptNext(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ValuePtr parameter
		, pkcs11::value_types::Ulong parameterLength
		, pkcs11::value_types::BytePtr plainTextPart
		, pkcs11::value_types::Ulong plainTextPartLength
		, pkcs11::value_types::BytePtr cipherTextPart
		, pkcs11::value_types::UlongPtr cipherTextPartLength
		, pkcs11::value_types::Flags flags
)
{
	flame_ide::unused(session);
	flame_ide::unused(parameter);
	flame_ide::unused(parameterLength);
	flame_ide::unused(plainTextPart);
	flame_ide::unused(plainTextPartLength);
	flame_ide::unused(cipherTextPart);
	flame_ide::unused(cipherTextPartLength);
	flame_ide::unused(flags);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType encryptFinal(
		pkcs11::value_types::SessionHandle session
)
{
	flame_ide::unused(session);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::message
