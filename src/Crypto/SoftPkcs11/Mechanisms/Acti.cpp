#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Acti.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Acti::Acti() noexcept = default;
Acti::~Acti() noexcept = default;

pkcs11::enums::Mechanism Acti::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ACTI;
}

pkcs11::structs::MechanismInfo Acti::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::SIGN
			& pkcs11::enums::MechanismFlags::VERIFY
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

