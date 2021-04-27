#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa/RsaXdot509.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RsaXdot509::RsaXdot509() noexcept = default;
RsaXdot509::~RsaXdot509() noexcept = default;

pkcs11::enums::Mechanism RsaXdot509::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_X_509;
}

pkcs11::structs::MechanismInfo RsaXdot509::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::ENCRYPT
			| pkcs11::enums::MechanismFlags::DECRYPT
			| pkcs11::enums::MechanismFlags::SIGN
			| pkcs11::enums::MechanismFlags::VERIFY
			| pkcs11::enums::MechanismFlags::SIGN_RECOVER
			| pkcs11::enums::MechanismFlags::VERIFY_RECOVER
			| pkcs11::enums::MechanismFlags::WRAP
			| pkcs11::enums::MechanismFlags::UNWRAP
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
