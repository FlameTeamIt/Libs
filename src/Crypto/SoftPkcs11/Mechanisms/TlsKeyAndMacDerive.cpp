#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TlsKeyAndMacDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

TlsKeyAndMacDerive::TlsKeyAndMacDerive() noexcept = default;
TlsKeyAndMacDerive::~TlsKeyAndMacDerive() noexcept = default;

pkcs11::enums::Mechanism TlsKeyAndMacDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS_KEY_AND_MAC_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

