#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha256HmacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha256HmacGeneral::Sha256HmacGeneral() noexcept = default;
Sha256HmacGeneral::~Sha256HmacGeneral() noexcept = default;

pkcs11::enums::Mechanism Sha256HmacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA256_HMAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

