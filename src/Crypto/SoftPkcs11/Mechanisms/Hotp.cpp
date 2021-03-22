#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Hotp.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Hotp::Hotp() noexcept = default;
Hotp::~Hotp() noexcept = default;

pkcs11::enums::Mechanism Hotp::getType() const noexcept
{
	return pkcs11::enums::Mechanism::HOTP;
}

pkcs11::structs::MechanismInfo Hotp::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::SIGN
			| pkcs11::enums::MechanismFlags::VERIFY
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

