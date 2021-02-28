#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc2MacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rc2MacGeneral::Rc2MacGeneral() noexcept = default;
Rc2MacGeneral::~Rc2MacGeneral() noexcept = default;

pkcs11::enums::Mechanism Rc2MacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RC2_MAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

