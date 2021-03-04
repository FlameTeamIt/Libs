#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha384HmacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha384HmacGeneral::Sha384HmacGeneral() noexcept = default;
Sha384HmacGeneral::~Sha384HmacGeneral() noexcept = default;

pkcs11::enums::Mechanism Sha384HmacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA384_HMAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

