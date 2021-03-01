#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd128Hmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RipeMd128Hmac::RipeMd128Hmac() noexcept = default;
RipeMd128Hmac::~RipeMd128Hmac() noexcept = default;

pkcs11::enums::Mechanism RipeMd128Hmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RIPEMD128_HMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

