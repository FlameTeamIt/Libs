#include <FlameIDE/../../src/Crypto/SoftPkcs11/Functions/ManagementFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
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
	flame_ide::unused(tokenPresent);
	flame_ide::unused(list);
	flame_ide::unused(count);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getSlotInfo(
		pkcs11::value_types::SlotId id
		, pkcs11::structs::SlotInfoPtr info
)
{
	flame_ide::unused(id);
	flame_ide::unused(info);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getTokenInfo(
		pkcs11::value_types::SlotId slotId
		, pkcs11::structs::TokenInfoPtr tokenInfo
)
{
	flame_ide::unused(slotId);
	flame_ide::unused(tokenInfo);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getMechanismList(
		pkcs11::value_types::SlotId slotId
		, pkcs11::value_types::MechanismPtr mechanismList
		, pkcs11::value_types::UlongPtr mechanismCount
)
{
	flame_ide::unused(slotId);
	flame_ide::unused(mechanismList);
	flame_ide::unused(mechanismCount);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType getMechanismInfo(
		pkcs11::value_types::SlotId slotId
		, pkcs11::value_types::Mechanism mechanismType
		, pkcs11::structs::MechanismInfoPtr mechanismInfo
)
{
	flame_ide::unused(slotId);
	flame_ide::unused(mechanismType);
	flame_ide::unused(mechanismInfo);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType initToken(
		pkcs11::value_types::SlotId slotId
		, pkcs11::value_types::Utf8CharPtr pin
		, pkcs11::value_types::Ulong pinLenength
		, pkcs11::value_types::Utf8CharPtr label
)
{
	flame_ide::unused(slotId);
	flame_ide::unused(pin);
	flame_ide::unused(pinLenength);
	flame_ide::unused(label);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

pkcs11::value_types::ReturnType initPin(
		pkcs11::value_types::SessionHandle session
		, pkcs11::value_types::Utf8CharPtr pin
		, pkcs11::value_types::Ulong pinLength
)
{
	flame_ide::unused(session);
	flame_ide::unused(pin);
	flame_ide::unused(pinLength);

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
	flame_ide::unused(session);
	flame_ide::unused(oldPin);
	flame_ide::unused(oldLength);
	flame_ide::unused(newPin);
	flame_ide::unused(newLength);

	return pkcs11::enums::value(pkcs11::enums::ReturnType::OK);
}

}}}} // flame_ide::soft_pkcs11::functions::management
