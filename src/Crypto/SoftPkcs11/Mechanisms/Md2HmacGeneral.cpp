#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md2HmacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Md2HmacGeneral::Md2HmacGeneral() noexcept = default;
Md2HmacGeneral::~Md2HmacGeneral() noexcept = default;

pkcs11::enums::Mechanism Md2HmacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::MD2_HMAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

