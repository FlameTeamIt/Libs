#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/DigestFunctions.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace digest
{

pkcs11::value_types::ReturnType init(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType update(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr dataPart
		, pkcs11::value_types::Ulong dataPartLength
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType final(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr digestData
		, pkcs11::value_types::UlongPtr digestDataLength
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType full(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr data
		, pkcs11::value_types::Ulong dataLength
		, pkcs11::value_types::BytePtr digestData
		, pkcs11::value_types::UlongPtr digestDataLength
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType key(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::ObjectHandle key
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::digest
