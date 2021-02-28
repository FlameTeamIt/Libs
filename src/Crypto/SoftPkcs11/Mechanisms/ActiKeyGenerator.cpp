#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ActiKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ActiKeyGenerator::ActiKeyGenerator() noexcept = default;
ActiKeyGenerator::~ActiKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism ActiKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ACTI_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

