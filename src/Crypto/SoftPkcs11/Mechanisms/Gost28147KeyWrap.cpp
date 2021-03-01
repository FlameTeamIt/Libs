#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gost28147KeyWrap.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Gost28147KeyWrap::Gost28147KeyWrap() noexcept = default;
Gost28147KeyWrap::~Gost28147KeyWrap() noexcept = default;

pkcs11::enums::Mechanism Gost28147KeyWrap::getType() const noexcept
{
	return pkcs11::enums::Mechanism::GOST28147_KEY_WRAP;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

