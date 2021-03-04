#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512HmacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512HmacGeneral::Sha512HmacGeneral() noexcept = default;
Sha512HmacGeneral::~Sha512HmacGeneral() noexcept = default;

pkcs11::enums::Mechanism Sha512HmacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_HMAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

