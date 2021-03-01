#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc4KeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rc4KeyGenerator::Rc4KeyGenerator() noexcept = default;
Rc4KeyGenerator::~Rc4KeyGenerator() noexcept = default;

pkcs11::enums::Mechanism Rc4KeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RC4_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

