#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gostr3411Hmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Gostr3411Hmac::Gostr3411Hmac() noexcept = default;
Gostr3411Hmac::~Gostr3411Hmac() noexcept = default;

pkcs11::enums::Mechanism Gostr3411Hmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::GOSTR3411_HMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

