#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/RandomGeneration.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace random_generation
{

pkcs11::value_types::ReturnType seedRandom(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr seed
		, pkcs11::value_types::Ulong seedLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(seed);
	flame_ide::unused(seedLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType generateRandom(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr randomData
		, pkcs11::value_types::Ulong randomLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(randomData);
	flame_ide::unused(randomLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::random_generation
