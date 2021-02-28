#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaX9dot31KeyPairGenerator.hpp>

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

}}} // namespace flame_ide::soft_pkcs11::mechanisms

