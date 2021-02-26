#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast5MacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast5MacGeneral::Cast5MacGeneral() noexcept = default;

Cast5MacGeneral::~Cast5MacGeneral() noexcept = default;

pkcs11::enums::Mechanism
Cast5MacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST5_MAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

