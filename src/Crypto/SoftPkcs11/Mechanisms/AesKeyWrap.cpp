#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesKeyWrap.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesKeyWrap::AesKeyWrap() noexcept = default;
AesKeyWrap::~AesKeyWrap() noexcept = default;

pkcs11::enums::Mechanism AesKeyWrap::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_KEY_WRAP;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

