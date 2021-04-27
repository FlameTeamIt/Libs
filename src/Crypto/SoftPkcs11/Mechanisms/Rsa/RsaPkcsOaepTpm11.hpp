#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RSA_PKCS_OAEP_TPM_1_1_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RSA_PKCS_OAEP_TPM_1_1_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct RsaPkcsOaepTpm11: public MechanismBase
{
	RsaPkcsOaepTpm11() noexcept;

	virtual ~RsaPkcsOaepTpm11() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;

	virtual pkcs11::structs::MechanismInfo getInfo() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RSA_PKCS_OAEP_TPM_1_1_HPP
