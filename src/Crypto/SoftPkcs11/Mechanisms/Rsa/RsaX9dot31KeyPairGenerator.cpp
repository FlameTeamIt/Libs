#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa/RsaX9dot31KeyPairGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RsaX9dot31KeyPairGenerator::RsaX9dot31KeyPairGenerator() noexcept = default;
RsaX9dot31KeyPairGenerator::~RsaX9dot31KeyPairGenerator() noexcept = default;

pkcs11::enums::Mechanism RsaX9dot31KeyPairGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_X9_31_KEY_PAIR_GEN;
}

pkcs11::structs::MechanismInfo RsaX9dot31KeyPairGenerator::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::GENERATE
			| pkcs11::enums::MechanismFlags::GENERATE_KEY_PAIR
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
