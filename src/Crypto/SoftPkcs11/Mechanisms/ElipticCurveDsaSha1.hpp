#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ECDSA_SHA1_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ECDSA_SHA1_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct ElipticCurveDsaSha1: public MechanismBase
{
	ElipticCurveDsaSha1() noexcept;

	virtual ~ElipticCurveDsaSha1() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ECDSA_SHA1_HPP
