#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesCbcPad::AesCbcPad() noexcept = default;
AesCbcPad::~AesCbcPad() noexcept = default;

pkcs11::enums::Mechanism AesCbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

