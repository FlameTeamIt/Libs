#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DiffieHellmanPkcsKeyPairGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DiffieHellmanPkcsKeyPairGenerator::DiffieHellmanPkcsKeyPairGenerator() noexcept = default;
DiffieHellmanPkcsKeyPairGenerator::~DiffieHellmanPkcsKeyPairGenerator() noexcept = default;

pkcs11::enums::Mechanism DiffieHellmanPkcsKeyPairGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DH_PKCS_KEY_PAIR_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

