#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa/Sha256RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha256RsaPkcs::Sha256RsaPkcs() noexcept = default;
Sha256RsaPkcs::~Sha256RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism Sha256RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA256_RSA_PKCS;
}

pkcs11::structs::MechanismInfo Sha256RsaPkcs::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::SIGN
			| pkcs11::enums::MechanismFlags::VERIFY
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
