#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SHA384_RSA_PKCS_PSS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SHA384_RSA_PKCS_PSS_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct Sha384RsaPkcsPss: public MechanismBase
{
	Sha384RsaPkcsPss() noexcept;

	virtual ~Sha384RsaPkcsPss() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;

	virtual pkcs11::structs::MechanismInfo getInfo() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SHA384_RSA_PKCS_PSS_HPP
