#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast128KeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast128KeyGenerator::Cast128KeyGenerator() noexcept = default;
Cast128KeyGenerator::~Cast128KeyGenerator() noexcept = default;

pkcs11::enums::Mechanism Cast128KeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST128_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

