#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TlsMasterKeyDeriveDiffieHellman.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

TlsMasterKeyDeriveDiffieHellman::TlsMasterKeyDeriveDiffieHellman() noexcept = default;
TlsMasterKeyDeriveDiffieHellman::~TlsMasterKeyDeriveDiffieHellman() noexcept = default;

pkcs11::enums::Mechanism TlsMasterKeyDeriveDiffieHellman::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS_MASTER_KEY_DERIVE_DH;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

