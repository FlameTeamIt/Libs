#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesCbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DesCbcPad::DesCbcPad() noexcept = default;
DesCbcPad::~DesCbcPad() noexcept = default;

pkcs11::enums::Mechanism DesCbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

