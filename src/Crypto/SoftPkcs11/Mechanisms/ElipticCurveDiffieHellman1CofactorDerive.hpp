#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ECDH1_COFACTOR_DERIVE_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ECDH1_COFACTOR_DERIVE_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct ElipticCurveDiffieHellman1CofactorDerive: public MechanismBase
{
	ElipticCurveDiffieHellman1CofactorDerive() noexcept;

	virtual ~ElipticCurveDiffieHellman1CofactorDerive() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_ECDH1_COFACTOR_DERIVE_HPP
