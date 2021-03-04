#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaCbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AriaCbcPad::AriaCbcPad() noexcept = default;
AriaCbcPad::~AriaCbcPad() noexcept = default;

pkcs11::enums::Mechanism AriaCbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ARIA_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

