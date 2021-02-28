#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast128CbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast128CbcPad::Cast128CbcPad() noexcept = default;
Cast128CbcPad::~Cast128CbcPad() noexcept = default;

pkcs11::enums::Mechanism Cast128CbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST128_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

