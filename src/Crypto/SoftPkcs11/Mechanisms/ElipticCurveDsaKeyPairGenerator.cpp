#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDsaKeyPairGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ElipticCurveDsaKeyPairGenerator::ElipticCurveDsaKeyPairGenerator() noexcept = default;

ElipticCurveDsaKeyPairGenerator::~ElipticCurveDsaKeyPairGenerator() noexcept = default;

pkcs11::enums::Mechanism
ElipticCurveDsaKeyPairGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ECDSA_KEY_PAIR_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

