#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa/RsaPkcsKeyPairGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RsaPkcsKeyPairGenerator::RsaPkcsKeyPairGenerator() noexcept = default;
RsaPkcsKeyPairGenerator::~RsaPkcsKeyPairGenerator() noexcept = default;

pkcs11::enums::Mechanism RsaPkcsKeyPairGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_PKCS_KEY_PAIR_GEN;
}

pkcs11::structs::MechanismInfo RsaPkcsKeyPairGenerator::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::GENERATE
			| pkcs11::enums::MechanismFlags::GENERATE_KEY_PAIR
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
