#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc2CbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rc2CbcPad::Rc2CbcPad() noexcept = default;
Rc2CbcPad::~Rc2CbcPad() noexcept = default;

pkcs11::enums::Mechanism Rc2CbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RC2_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

