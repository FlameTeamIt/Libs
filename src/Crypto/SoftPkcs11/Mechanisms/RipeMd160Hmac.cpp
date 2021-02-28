#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd160Hmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RipeMd160Hmac::RipeMd160Hmac() noexcept = default;
RipeMd160Hmac::~RipeMd160Hmac() noexcept = default;

pkcs11::enums::Mechanism RipeMd160Hmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RIPEMD160_HMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

