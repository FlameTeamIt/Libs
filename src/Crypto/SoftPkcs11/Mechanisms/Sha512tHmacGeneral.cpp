#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512tHmacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512tHmacGeneral::Sha512tHmacGeneral() noexcept = default;
Sha512tHmacGeneral::~Sha512tHmacGeneral() noexcept = default;

pkcs11::enums::Mechanism Sha512tHmacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_T_HMAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

