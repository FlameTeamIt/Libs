#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha224Hmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha224Hmac::Sha224Hmac() noexcept = default;
Sha224Hmac::~Sha224Hmac() noexcept = default;

pkcs11::enums::Mechanism Sha224Hmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA224_HMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

