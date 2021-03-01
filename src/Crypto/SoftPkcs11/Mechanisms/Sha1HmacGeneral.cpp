#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha1HmacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha1HmacGeneral::Sha1HmacGeneral() noexcept = default;
Sha1HmacGeneral::~Sha1HmacGeneral() noexcept = default;

pkcs11::enums::Mechanism Sha1HmacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA_1_HMAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

