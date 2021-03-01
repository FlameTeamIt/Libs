#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SkipjackKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SkipjackKeyGenerator::SkipjackKeyGenerator() noexcept = default;
SkipjackKeyGenerator::~SkipjackKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism SkipjackKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SKIPJACK_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

