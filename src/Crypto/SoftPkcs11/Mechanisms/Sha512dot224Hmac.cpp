#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot224Hmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512dot224Hmac::Sha512dot224Hmac() noexcept = default;
Sha512dot224Hmac::~Sha512dot224Hmac() noexcept = default;

pkcs11::enums::Mechanism Sha512dot224Hmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_224_HMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

