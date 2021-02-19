#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/ManagementFunctions.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace functions
{namespace management
{

pkcs11::value_types::ReturnType getSlotList(
		pkcs11::value_types::Bool tokenPresent
		, pkcs11::value_types::SlotIdPtr list
		, pkcs11::value_types::UlongPtr count
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getSlotInfo(
		pkcs11::value_types::SlotId id
		, pkcs11::structs::SlotInfoPtr info
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getTokenInfo(
		pkcs11::value_types::SlotId slotId
		, pkcs11::structs::TokenInfoPtr tokenInfo
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getMechanismList(
		pkcs11::value_types::SlotId slotId
		, pkcs11::value_types::MechanismPtr mechanismList
		, pkcs11::value_types::UlongPtr mechanismCount
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getMechanismInfo(
		pkcs11::value_types::SlotId slotId
		, pkcs11::value_types::Mechanism mechanismType
		, pkcs11::structs::MechanismInfoPtr mechanismInfo
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType initToken(
		pkcs11::value_types::SlotId slotId
		, pkcs11::value_types::Utf8CharPtr pin
		, pkcs11::value_types::Ulong pinLenength
		, pkcs11::value_types::Utf8CharPtr label
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType initPin(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::Utf8CharPtr pin
		, pkcs11::value_types::Ulong pinLength
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType setPin(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::Utf8CharPtr oldPin
		, pkcs11::value_types::Ulong oldLength
		, pkcs11::value_types::Utf8CharPtr newPin
		, pkcs11::value_types::Ulong newLength
)
{
	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::management
