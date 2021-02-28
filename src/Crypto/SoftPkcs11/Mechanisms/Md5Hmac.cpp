#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md5Hmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Md5Hmac::Md5Hmac() noexcept = default;
Md5Hmac::~Md5Hmac() noexcept = default;

pkcs11::enums::Mechanism Md5Hmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::MD5_HMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

