#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa/Sha384RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha384RsaPkcs::Sha384RsaPkcs() noexcept = default;
Sha384RsaPkcs::~Sha384RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism Sha384RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA384_RSA_PKCS;
}

pkcs11::structs::MechanismInfo Sha384RsaPkcs::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::SIGN
			| pkcs11::enums::MechanismFlags::VERIFY
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
