#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbaSha1WithSha1Hmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

PbaSha1WithSha1Hmac::PbaSha1WithSha1Hmac() noexcept = default;
PbaSha1WithSha1Hmac::~PbaSha1WithSha1Hmac() noexcept = default;

pkcs11::enums::Mechanism PbaSha1WithSha1Hmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PBA_SHA1_WITH_SHA1_HMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

