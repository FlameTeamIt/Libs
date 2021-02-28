#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512Hmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512Hmac::Sha512Hmac() noexcept = default;
Sha512Hmac::~Sha512Hmac() noexcept = default;

pkcs11::enums::Mechanism Sha512Hmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_HMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

