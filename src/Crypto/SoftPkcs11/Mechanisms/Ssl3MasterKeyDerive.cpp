#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Ssl3MasterKeyDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Ssl3MasterKeyDerive::Ssl3MasterKeyDerive() noexcept = default;
Ssl3MasterKeyDerive::~Ssl3MasterKeyDerive() noexcept = default;

pkcs11::enums::Mechanism Ssl3MasterKeyDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SSL3_MASTER_KEY_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

