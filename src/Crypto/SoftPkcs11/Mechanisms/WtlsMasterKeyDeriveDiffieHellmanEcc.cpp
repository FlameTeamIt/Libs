#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/WtlsMasterKeyDeriveDiffieHellmanEcc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

WtlsMasterKeyDeriveDiffieHellmanEcc::WtlsMasterKeyDeriveDiffieHellmanEcc() noexcept = default;
WtlsMasterKeyDeriveDiffieHellmanEcc::~WtlsMasterKeyDeriveDiffieHellmanEcc() noexcept = default;

pkcs11::enums::Mechanism WtlsMasterKeyDeriveDiffieHellmanEcc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::WTLS_MASTER_KEY_DERIVE_DH_ECC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

