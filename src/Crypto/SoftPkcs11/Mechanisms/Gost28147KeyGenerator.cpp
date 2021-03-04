#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gost28147KeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Gost28147KeyGenerator::Gost28147KeyGenerator() noexcept = default;
Gost28147KeyGenerator::~Gost28147KeyGenerator() noexcept = default;

pkcs11::enums::Mechanism Gost28147KeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::GOST28147_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

