#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha384Hmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha384Hmac::Sha384Hmac() noexcept = default;
Sha384Hmac::~Sha384Hmac() noexcept = default;

pkcs11::enums::Mechanism Sha384Hmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA384_HMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

