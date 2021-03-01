#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaAesKeyWrap.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RsaAesKeyWrap::RsaAesKeyWrap() noexcept = default;
RsaAesKeyWrap::~RsaAesKeyWrap() noexcept = default;

pkcs11::enums::Mechanism RsaAesKeyWrap::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_AES_KEY_WRAP;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

