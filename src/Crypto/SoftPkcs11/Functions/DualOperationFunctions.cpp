#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/DualOperationFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace dual_operations
{

pkcs11::value_types::ReturnType digestEncryptUpdate(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr dataPart
		, pkcs11::value_types::Ulong dataPartLength
		, pkcs11::value_types::BytePtr encryptedDataPart
		, pkcs11::value_types::UlongPtr encryptedDataPartLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(dataPart);
	flame_ide::unused(dataPartLength);
	flame_ide::unused(encryptedDataPart);
	flame_ide::unused(encryptedDataPartLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType decryptDigestUpdate(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr encryptedDataPart
		, pkcs11::value_types::Ulong encryptedDataPartLength
		, pkcs11::value_types::BytePtr dataPart
		, pkcs11::value_types::UlongPtr dataPartLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(encryptedDataPart);
	flame_ide::unused(encryptedDataPartLength);
	flame_ide::unused(dataPart);
	flame_ide::unused(dataPartLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType signEncryptUpdate(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr dataPart
		, pkcs11::value_types::Ulong dataPartLength
		, pkcs11::value_types::BytePtr encryptedDataPart
		, pkcs11::value_types::UlongPtr encryptedDataPartLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(dataPart);
	flame_ide::unused(dataPartLength);
	flame_ide::unused(encryptedDataPart);
	flame_ide::unused(encryptedDataPartLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType decryptVerifyUpdate(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::BytePtr encryptedDataPart
		, pkcs11::value_types::Ulong encryptedDataPartLength
		, pkcs11::value_types::BytePtr dataPart
		, pkcs11::value_types::UlongPtr dataPartLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(encryptedDataPart);
	flame_ide::unused(encryptedDataPartLength);
	flame_ide::unused(dataPart);
	flame_ide::unused(dataPartLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::dual_operations
