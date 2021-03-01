#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast3MacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast3MacGeneral::Cast3MacGeneral() noexcept = default;
Cast3MacGeneral::~Cast3MacGeneral() noexcept = default;

pkcs11::enums::Mechanism Cast3MacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST3_MAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

