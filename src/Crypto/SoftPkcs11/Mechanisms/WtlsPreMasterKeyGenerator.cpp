#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/WtlsPreMasterKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

WtlsPreMasterKeyGenerator::WtlsPreMasterKeyGenerator() noexcept = default;
WtlsPreMasterKeyGenerator::~WtlsPreMasterKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism WtlsPreMasterKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::WTLS_PRE_MASTER_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

