#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCmacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesCmacGeneral::AesCmacGeneral() noexcept = default;
AesCmacGeneral::~AesCmacGeneral() noexcept = default;

pkcs11::enums::Mechanism AesCmacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_CMAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

