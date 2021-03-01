#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TlsPreMasterKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

TlsPreMasterKeyGenerator::TlsPreMasterKeyGenerator() noexcept = default;
TlsPreMasterKeyGenerator::~TlsPreMasterKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism TlsPreMasterKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS_PRE_MASTER_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

