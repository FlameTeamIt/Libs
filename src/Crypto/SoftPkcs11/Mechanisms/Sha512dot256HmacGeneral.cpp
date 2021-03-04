#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot256HmacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512dot256HmacGeneral::Sha512dot256HmacGeneral() noexcept = default;
Sha512dot256HmacGeneral::~Sha512dot256HmacGeneral() noexcept = default;

pkcs11::enums::Mechanism Sha512dot256HmacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_256_HMAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

