#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa/Rsa9796.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rsa9796::Rsa9796() noexcept = default;
Rsa9796::~Rsa9796() noexcept = default;

pkcs11::enums::Mechanism Rsa9796::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_9796;
}

pkcs11::structs::MechanismInfo Rsa9796::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::SIGN
			| pkcs11::enums::MechanismFlags::VERIFY
			| pkcs11::enums::MechanismFlags::SIGN_RECOVER
			| pkcs11::enums::MechanismFlags::VERIFY_RECOVER
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
