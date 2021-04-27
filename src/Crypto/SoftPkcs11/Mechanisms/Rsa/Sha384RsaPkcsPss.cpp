#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa/Sha384RsaPkcsPss.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha384RsaPkcsPss::Sha384RsaPkcsPss() noexcept = default;
Sha384RsaPkcsPss::~Sha384RsaPkcsPss() noexcept = default;

pkcs11::enums::Mechanism Sha384RsaPkcsPss::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA384_RSA_PKCS_PSS;
}

pkcs11::structs::MechanismInfo Sha384RsaPkcsPss::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info;
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::SIGN
			| pkcs11::enums::MechanismFlags::VERIFY
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
