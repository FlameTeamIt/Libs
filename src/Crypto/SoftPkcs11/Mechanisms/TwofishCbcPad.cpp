#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TwofishCbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

TwofishCbcPad::TwofishCbcPad() noexcept = default;
TwofishCbcPad::~TwofishCbcPad() noexcept = default;

pkcs11::enums::Mechanism TwofishCbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TWOFISH_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

