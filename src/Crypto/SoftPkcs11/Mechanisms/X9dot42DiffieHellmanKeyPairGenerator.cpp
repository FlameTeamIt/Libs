#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/X9dot42DiffieHellmanKeyPairGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

X9dot42DiffieHellmanKeyPairGenerator::X9dot42DiffieHellmanKeyPairGenerator() noexcept = default;
X9dot42DiffieHellmanKeyPairGenerator::~X9dot42DiffieHellmanKeyPairGenerator() noexcept = default;

pkcs11::enums::Mechanism X9dot42DiffieHellmanKeyPairGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::X9_42_DH_KEY_PAIR_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

