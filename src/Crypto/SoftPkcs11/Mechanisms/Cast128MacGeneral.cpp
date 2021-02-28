#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast128MacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast128MacGeneral::Cast128MacGeneral() noexcept = default;
Cast128MacGeneral::~Cast128MacGeneral() noexcept = default;

pkcs11::enums::Mechanism Cast128MacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST128_MAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

