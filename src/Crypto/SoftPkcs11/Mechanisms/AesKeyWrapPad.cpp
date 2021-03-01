#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesKeyWrapPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesKeyWrapPad::AesKeyWrapPad() noexcept = default;
AesKeyWrapPad::~AesKeyWrapPad() noexcept = default;

pkcs11::enums::Mechanism AesKeyWrapPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_KEY_WRAP_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

