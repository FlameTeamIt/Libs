#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa/RsaPkcsOaep.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RsaPkcsOaep::RsaPkcsOaep() noexcept = default;
RsaPkcsOaep::~RsaPkcsOaep() noexcept = default;

pkcs11::enums::Mechanism RsaPkcsOaep::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_PKCS_OAEP;
}

pkcs11::structs::MechanismInfo RsaPkcsOaep::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::ENCRYPT
			| pkcs11::enums::MechanismFlags::DECRYPT
			| pkcs11::enums::MechanismFlags::WRAP
			| pkcs11::enums::MechanismFlags::UNWRAP
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
