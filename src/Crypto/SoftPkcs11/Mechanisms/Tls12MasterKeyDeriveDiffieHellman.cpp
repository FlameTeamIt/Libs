#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls12MasterKeyDeriveDiffieHellman.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Tls12MasterKeyDeriveDiffieHellman::Tls12MasterKeyDeriveDiffieHellman() noexcept = default;
Tls12MasterKeyDeriveDiffieHellman::~Tls12MasterKeyDeriveDiffieHellman() noexcept = default;

pkcs11::enums::Mechanism Tls12MasterKeyDeriveDiffieHellman::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS12_MASTER_KEY_DERIVE_DH;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

