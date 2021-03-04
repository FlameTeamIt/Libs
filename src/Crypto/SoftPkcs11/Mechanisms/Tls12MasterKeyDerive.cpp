#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls12MasterKeyDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Tls12MasterKeyDerive::Tls12MasterKeyDerive() noexcept = default;
Tls12MasterKeyDerive::~Tls12MasterKeyDerive() noexcept = default;

pkcs11::enums::Mechanism Tls12MasterKeyDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS12_MASTER_KEY_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

