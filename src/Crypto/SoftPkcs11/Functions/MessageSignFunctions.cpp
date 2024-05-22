#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/MessageSignFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace message
{

pkcs11::value_types::ReturnType signInit(
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

pkcs11::value_types::ReturnType sign(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ValuePtr parameter
		, pkcs11::value_types::Ulong parameterLength
		, pkcs11::value_types::BytePtr data
		, pkcs11::value_types::Ulong dataLength
		, pkcs11::value_types::BytePtr signature
		, pkcs11::value_types::UlongPtr signatureLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(parameter);
	flame_ide::unused(parameterLength);
	flame_ide::unused(data);
	flame_ide::unused(dataLength);
	flame_ide::unused(signature);
	flame_ide::unused(signatureLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType signBegin(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ValuePtr parameter
		, pkcs11::value_types::Ulong parameterLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(parameter);
	flame_ide::unused(parameterLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType signNext(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ValuePtr parameter
		, pkcs11::value_types::Ulong parameterLength
		, pkcs11::value_types::BytePtr sata
		, pkcs11::value_types::Ulong dataLength
		, pkcs11::value_types::BytePtr signature
		, pkcs11::value_types::UlongPtr signatureLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(parameter);
	flame_ide::unused(parameterLength);
	flame_ide::unused(sata);
	flame_ide::unused(dataLength);
	flame_ide::unused(signature);
	flame_ide::unused(signatureLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType signFinal(
		pkcs11::value_types::SessionHandle session
)
{
	flame_ide::unused(session);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::message
