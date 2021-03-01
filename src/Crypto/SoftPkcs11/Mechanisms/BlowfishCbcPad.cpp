#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BlowfishCbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

BlowfishCbcPad::BlowfishCbcPad() noexcept = default;
BlowfishCbcPad::~BlowfishCbcPad() noexcept = default;

pkcs11::enums::Mechanism BlowfishCbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::BLOWFISH_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

