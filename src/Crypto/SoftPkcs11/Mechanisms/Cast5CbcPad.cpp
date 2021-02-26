#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast5CbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast5CbcPad::Cast5CbcPad() noexcept = default;

Cast5CbcPad::~Cast5CbcPad() noexcept = default;

pkcs11::enums::Mechanism
Cast5CbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST5_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

