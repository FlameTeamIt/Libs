#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd128HmacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RipeMd128HmacGeneral::RipeMd128HmacGeneral() noexcept = default;
RipeMd128HmacGeneral::~RipeMd128HmacGeneral() noexcept = default;

pkcs11::enums::Mechanism RipeMd128HmacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RIPEMD128_HMAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

