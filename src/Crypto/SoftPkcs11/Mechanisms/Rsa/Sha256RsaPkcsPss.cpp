#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa/Sha256RsaPkcsPss.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha256RsaPkcsPss::Sha256RsaPkcsPss() noexcept = default;
Sha256RsaPkcsPss::~Sha256RsaPkcsPss() noexcept = default;

pkcs11::enums::Mechanism Sha256RsaPkcsPss::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA256_RSA_PKCS_PSS;
}

pkcs11::structs::MechanismInfo Sha256RsaPkcsPss::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::SIGN
			| pkcs11::enums::MechanismFlags::VERIFY
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
