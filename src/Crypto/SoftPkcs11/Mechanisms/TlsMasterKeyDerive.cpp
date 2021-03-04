#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TlsMasterKeyDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

TlsMasterKeyDerive::TlsMasterKeyDerive() noexcept = default;
TlsMasterKeyDerive::~TlsMasterKeyDerive() noexcept = default;

pkcs11::enums::Mechanism TlsMasterKeyDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS_MASTER_KEY_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

