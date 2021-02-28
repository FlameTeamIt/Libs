#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot256Hmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512dot256Hmac::Sha512dot256Hmac() noexcept = default;
Sha512dot256Hmac::~Sha512dot256Hmac() noexcept = default;

pkcs11::enums::Mechanism Sha512dot256Hmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_256_HMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

