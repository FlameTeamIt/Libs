#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa/Sha1RsaX9dot31.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha1RsaX9dot31::Sha1RsaX9dot31() noexcept = default;
Sha1RsaX9dot31::~Sha1RsaX9dot31() noexcept = default;

pkcs11::enums::Mechanism Sha1RsaX9dot31::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA1_RSA_X9_31;
}

pkcs11::structs::MechanismInfo Sha1RsaX9dot31::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::SIGN
			| pkcs11::enums::MechanismFlags::VERIFY
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
