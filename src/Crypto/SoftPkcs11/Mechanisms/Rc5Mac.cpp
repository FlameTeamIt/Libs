#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc5Mac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rc5Mac::Rc5Mac() noexcept = default;
Rc5Mac::~Rc5Mac() noexcept = default;

pkcs11::enums::Mechanism Rc5Mac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RC5_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

