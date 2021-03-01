#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast3KeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast3KeyGenerator::Cast3KeyGenerator() noexcept = default;
Cast3KeyGenerator::~Cast3KeyGenerator() noexcept = default;

pkcs11::enums::Mechanism Cast3KeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST3_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

