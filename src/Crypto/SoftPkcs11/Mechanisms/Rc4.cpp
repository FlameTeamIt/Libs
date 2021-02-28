#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc4.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rc4::Rc4() noexcept = default;
Rc4::~Rc4() noexcept = default;

pkcs11::enums::Mechanism Rc4::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RC4;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

