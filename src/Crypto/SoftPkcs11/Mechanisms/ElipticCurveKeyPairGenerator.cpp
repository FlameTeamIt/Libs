#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveKeyPairGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ElipticCurveKeyPairGenerator::ElipticCurveKeyPairGenerator() noexcept = default;
ElipticCurveKeyPairGenerator::~ElipticCurveKeyPairGenerator() noexcept = default;

pkcs11::enums::Mechanism ElipticCurveKeyPairGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::EC_KEY_PAIR_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

