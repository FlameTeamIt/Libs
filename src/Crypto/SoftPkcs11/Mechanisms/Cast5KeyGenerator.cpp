#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast5KeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast5KeyGenerator::Cast5KeyGenerator() noexcept = default;

Cast5KeyGenerator::~Cast5KeyGenerator() noexcept = default;

pkcs11::enums::Mechanism
Cast5KeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST5_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

