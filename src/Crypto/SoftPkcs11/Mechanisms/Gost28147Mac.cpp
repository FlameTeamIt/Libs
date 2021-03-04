#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gost28147Mac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Gost28147Mac::Gost28147Mac() noexcept = default;
Gost28147Mac::~Gost28147Mac() noexcept = default;

pkcs11::enums::Mechanism Gost28147Mac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::GOST28147_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

