#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls12KeyAndMacDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Tls12KeyAndMacDerive::Tls12KeyAndMacDerive() noexcept = default;
Tls12KeyAndMacDerive::~Tls12KeyAndMacDerive() noexcept = default;

pkcs11::enums::Mechanism Tls12KeyAndMacDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS12_KEY_AND_MAC_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

