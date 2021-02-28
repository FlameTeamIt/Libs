#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc2KeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rc2KeyGenerator::Rc2KeyGenerator() noexcept = default;
Rc2KeyGenerator::~Rc2KeyGenerator() noexcept = default;

pkcs11::enums::Mechanism Rc2KeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RC2_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

