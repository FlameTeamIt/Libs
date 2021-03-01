#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DesKeyGenerator::DesKeyGenerator() noexcept = default;
DesKeyGenerator::~DesKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism DesKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

