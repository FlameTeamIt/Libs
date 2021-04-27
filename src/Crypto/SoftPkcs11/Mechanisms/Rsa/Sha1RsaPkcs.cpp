#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa/Sha1RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha1RsaPkcs::Sha1RsaPkcs() noexcept = default;
Sha1RsaPkcs::~Sha1RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism Sha1RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA1_RSA_PKCS;
}

pkcs11::structs::MechanismInfo Sha1RsaPkcs::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::SIGN
			| pkcs11::enums::MechanismFlags::VERIFY
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
