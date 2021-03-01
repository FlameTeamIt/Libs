#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaPkcsKeyPairGenerator.hpp>

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

}}} // namespace flame_ide::soft_pkcs11::mechanisms

