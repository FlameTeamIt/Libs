#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BatonKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

BatonKeyGenerator::BatonKeyGenerator() noexcept = default;
BatonKeyGenerator::~BatonKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism BatonKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::BATON_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

