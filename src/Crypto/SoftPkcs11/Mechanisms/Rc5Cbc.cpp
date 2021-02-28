#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc5Cbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rc5Cbc::Rc5Cbc() noexcept = default;
Rc5Cbc::~Rc5Cbc() noexcept = default;

pkcs11::enums::Mechanism Rc5Cbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RC5_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

