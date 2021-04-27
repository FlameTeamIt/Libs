#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SHA256_RSA_PKCS_PSS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SHA256_RSA_PKCS_PSS_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct Sha256RsaPkcsPss: public MechanismBase
{
	Sha256RsaPkcsPss() noexcept;

	virtual ~Sha256RsaPkcsPss() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;

	virtual pkcs11::structs::MechanismInfo getInfo() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SHA256_RSA_PKCS_PSS_HPP
