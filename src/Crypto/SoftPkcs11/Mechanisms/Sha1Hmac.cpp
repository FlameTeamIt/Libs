#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha1Hmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha1Hmac::Sha1Hmac() noexcept = default;
Sha1Hmac::~Sha1Hmac() noexcept = default;

pkcs11::enums::Mechanism Sha1Hmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA_1_HMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

