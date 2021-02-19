#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/OtherFunctions.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace other
{

pkcs11::value_types::ReturnType seedRandom(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr seed
		, pkcs11::value_types::Ulong seedLength
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType generateRandom(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr randomData
		, pkcs11::value_types::Ulong randomLength
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::other
