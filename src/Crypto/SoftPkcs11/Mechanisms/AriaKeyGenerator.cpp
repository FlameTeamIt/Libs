#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AriaKeyGenerator::AriaKeyGenerator() noexcept = default;
AriaKeyGenerator::~AriaKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism AriaKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ARIA_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

