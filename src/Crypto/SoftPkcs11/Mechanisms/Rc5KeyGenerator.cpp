#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc5KeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rc5KeyGenerator::Rc5KeyGenerator() noexcept = default;
Rc5KeyGenerator::~Rc5KeyGenerator() noexcept = default;

pkcs11::enums::Mechanism Rc5KeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RC5_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

