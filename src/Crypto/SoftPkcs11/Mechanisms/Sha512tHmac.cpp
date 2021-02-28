#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512tHmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512tHmac::Sha512tHmac() noexcept = default;
Sha512tHmac::~Sha512tHmac() noexcept = default;

pkcs11::enums::Mechanism Sha512tHmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_T_HMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

