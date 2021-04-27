#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa/RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RsaPkcs::RsaPkcs() noexcept = default;
RsaPkcs::~RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_PKCS;
}

pkcs11::structs::MechanismInfo RsaPkcs::getInfo() const noexcept
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
