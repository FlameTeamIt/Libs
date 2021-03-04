#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/WtlsMasterKeyDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

WtlsMasterKeyDerive::WtlsMasterKeyDerive() noexcept = default;
WtlsMasterKeyDerive::~WtlsMasterKeyDerive() noexcept = default;

pkcs11::enums::Mechanism WtlsMasterKeyDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::WTLS_MASTER_KEY_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

