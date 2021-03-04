#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Ssl3MasterKeyDeriveDiffieHellman.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Ssl3MasterKeyDeriveDiffieHellman::Ssl3MasterKeyDeriveDiffieHellman() noexcept = default;
Ssl3MasterKeyDeriveDiffieHellman::~Ssl3MasterKeyDeriveDiffieHellman() noexcept = default;

pkcs11::enums::Mechanism Ssl3MasterKeyDeriveDiffieHellman::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SSL3_MASTER_KEY_DERIVE_DH;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

