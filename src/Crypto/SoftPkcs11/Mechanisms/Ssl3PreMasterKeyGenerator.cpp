#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Ssl3PreMasterKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Ssl3PreMasterKeyGenerator::Ssl3PreMasterKeyGenerator() noexcept = default;
Ssl3PreMasterKeyGenerator::~Ssl3PreMasterKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism Ssl3PreMasterKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SSL3_PRE_MASTER_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

