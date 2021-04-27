#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa/Sha512RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512RsaPkcs::Sha512RsaPkcs() noexcept = default;
Sha512RsaPkcs::~Sha512RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism Sha512RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_RSA_PKCS;
}

pkcs11::structs::MechanismInfo Sha512RsaPkcs::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::SIGN
			| pkcs11::enums::MechanismFlags::VERIFY
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
