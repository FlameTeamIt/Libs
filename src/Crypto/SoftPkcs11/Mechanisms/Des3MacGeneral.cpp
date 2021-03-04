#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3MacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Des3MacGeneral::Des3MacGeneral() noexcept = default;
Des3MacGeneral::~Des3MacGeneral() noexcept = default;

pkcs11::enums::Mechanism Des3MacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES3_MAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

