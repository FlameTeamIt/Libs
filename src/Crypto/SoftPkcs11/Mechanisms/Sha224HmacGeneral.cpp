#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha224HmacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha224HmacGeneral::Sha224HmacGeneral() noexcept = default;
Sha224HmacGeneral::~Sha224HmacGeneral() noexcept = default;

pkcs11::enums::Mechanism Sha224HmacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA224_HMAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

