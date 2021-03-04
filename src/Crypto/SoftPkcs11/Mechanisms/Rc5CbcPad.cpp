#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc5CbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rc5CbcPad::Rc5CbcPad() noexcept = default;
Rc5CbcPad::~Rc5CbcPad() noexcept = default;

pkcs11::enums::Mechanism Rc5CbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RC5_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

