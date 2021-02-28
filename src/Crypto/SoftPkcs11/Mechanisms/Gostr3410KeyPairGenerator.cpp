#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gostr3410KeyPairGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Gostr3410KeyPairGenerator::Gostr3410KeyPairGenerator() noexcept = default;
Gostr3410KeyPairGenerator::~Gostr3410KeyPairGenerator() noexcept = default;

pkcs11::enums::Mechanism Gostr3410KeyPairGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::GOSTR3410_KEY_PAIR_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

