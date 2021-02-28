#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc2Mac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rc2Mac::Rc2Mac() noexcept = default;
Rc2Mac::~Rc2Mac() noexcept = default;

pkcs11::enums::Mechanism Rc2Mac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RC2_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

