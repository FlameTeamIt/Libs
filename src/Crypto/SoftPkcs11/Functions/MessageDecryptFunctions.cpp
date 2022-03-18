#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/MessageDecryptFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace message
{

pkcs11::value_types::ReturnType decryptInit(
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

pkcs11::value_types::ReturnType decrypt(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ValuePtr parameter
		, pkcs11::value_types::Ulong parameterLength
		, pkcs11::value_types::BytePtr associatedData
		, pkcs11::value_types::Ulong associatedDataLength
		, pkcs11::value_types::BytePtr cipherText
		, pkcs11::value_types::Ulong cipherTextLength
		, pkcs11::value_types::BytePtr plainText
		, pkcs11::value_types::UlongPtr plainTextLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(parameter);
	flame_ide::unused(parameterLength);
	flame_ide::unused(associatedData);
	flame_ide::unused(associatedDataLength);
	flame_ide::unused(cipherText);
	flame_ide::unused(cipherTextLength);
	flame_ide::unused(plainText);
	flame_ide::unused(plainTextLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType decryptBegin(
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

pkcs11::value_types::ReturnType decryptNext(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ValuePtr parameter
		, pkcs11::value_types::Ulong parameterLength
		, pkcs11::value_types::BytePtr cipherText
		, pkcs11::value_types::Ulong cipherTextLength
		, pkcs11::value_types::BytePtr plainText
		, pkcs11::value_types::UlongPtr plainTextLength
		, pkcs11::value_types::Flags flags
)
{
	flame_ide::unused(session);
	flame_ide::unused(parameter);
	flame_ide::unused(parameterLength);
	flame_ide::unused(cipherText);
	flame_ide::unused(cipherTextLength);
	flame_ide::unused(plainText);
	flame_ide::unused(plainTextLength);
	flame_ide::unused(flags);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType decryptFinal(
		pkcs11::value_types::SessionHandle session
)
{
	flame_ide::unused(session);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::message
