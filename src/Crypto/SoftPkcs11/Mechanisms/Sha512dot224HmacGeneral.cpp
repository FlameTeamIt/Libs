#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot224HmacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512dot224HmacGeneral::Sha512dot224HmacGeneral() noexcept = default;
Sha512dot224HmacGeneral::~Sha512dot224HmacGeneral() noexcept = default;

pkcs11::enums::Mechanism Sha512dot224HmacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_224_HMAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

