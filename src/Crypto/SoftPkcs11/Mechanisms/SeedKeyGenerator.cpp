#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SeedKeyGenerator::SeedKeyGenerator() noexcept = default;
SeedKeyGenerator::~SeedKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism SeedKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SEED_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

