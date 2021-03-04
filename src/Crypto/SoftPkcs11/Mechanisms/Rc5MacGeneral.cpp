#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc5MacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rc5MacGeneral::Rc5MacGeneral() noexcept = default;
Rc5MacGeneral::~Rc5MacGeneral() noexcept = default;

pkcs11::enums::Mechanism Rc5MacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RC5_MAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

