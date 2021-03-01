#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md2Hmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Md2Hmac::Md2Hmac() noexcept = default;
Md2Hmac::~Md2Hmac() noexcept = default;

pkcs11::enums::Mechanism Md2Hmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::MD2_HMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

