#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md5HmacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Md5HmacGeneral::Md5HmacGeneral() noexcept = default;
Md5HmacGeneral::~Md5HmacGeneral() noexcept = default;

pkcs11::enums::Mechanism Md5HmacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::MD5_HMAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

