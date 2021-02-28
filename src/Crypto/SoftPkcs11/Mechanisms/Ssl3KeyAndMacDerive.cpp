#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Ssl3KeyAndMacDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Ssl3KeyAndMacDerive::Ssl3KeyAndMacDerive() noexcept = default;
Ssl3KeyAndMacDerive::~Ssl3KeyAndMacDerive() noexcept = default;

pkcs11::enums::Mechanism Ssl3KeyAndMacDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SSL3_KEY_AND_MAC_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

