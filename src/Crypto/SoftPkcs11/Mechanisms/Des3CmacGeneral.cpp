#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3CmacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Des3CmacGeneral::Des3CmacGeneral() noexcept = default;
Des3CmacGeneral::~Des3CmacGeneral() noexcept = default;

pkcs11::enums::Mechanism Des3CmacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES3_CMAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

