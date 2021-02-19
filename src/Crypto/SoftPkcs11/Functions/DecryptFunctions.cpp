#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/DecryptFunctions.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace decrypt
{

pkcs11::value_types::ReturnType init(
		pkcs11::value_types::SessionHandle session
		, pkcs11::structs::MechanismPtr mechanism
		, pkcs11::value_types::ObjectHandle object
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType update(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr encryptedDataPart
		, pkcs11::value_types::Ulong encryptedDataPartLength
		, pkcs11::value_types::BytePtr dataPart
		, pkcs11::value_types::UlongPtr dataPartLength
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType final(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr lastPart
		, pkcs11::value_types::UlongPtr lastPartLength
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType full(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr encryptedData
		, pkcs11::value_types::Ulong encryptedDataLength
		, pkcs11::value_types::BytePtr data
		, pkcs11::value_types::UlongPtr dataLength
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::decrypt
