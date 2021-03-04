#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd160HmacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RipeMd160HmacGeneral::RipeMd160HmacGeneral() noexcept = default;
RipeMd160HmacGeneral::~RipeMd160HmacGeneral() noexcept = default;

pkcs11::enums::Mechanism RipeMd160HmacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RIPEMD160_HMAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

