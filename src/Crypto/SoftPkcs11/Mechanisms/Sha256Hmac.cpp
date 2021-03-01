#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha256Hmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha256Hmac::Sha256Hmac() noexcept = default;
Sha256Hmac::~Sha256Hmac() noexcept = default;

pkcs11::enums::Mechanism Sha256Hmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA256_HMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

