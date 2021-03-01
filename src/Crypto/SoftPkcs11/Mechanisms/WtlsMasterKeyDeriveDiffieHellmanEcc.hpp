#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_WTLS_MASTER_KEY_DERIVE_DH_ECC_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_WTLS_MASTER_KEY_DERIVE_DH_ECC_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct WtlsMasterKeyDeriveDiffieHellmanEcc: public MechanismBase
{
	WtlsMasterKeyDeriveDiffieHellmanEcc() noexcept;

	virtual ~WtlsMasterKeyDeriveDiffieHellmanEcc() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_WTLS_MASTER_KEY_DERIVE_DH_ECC_HPP
