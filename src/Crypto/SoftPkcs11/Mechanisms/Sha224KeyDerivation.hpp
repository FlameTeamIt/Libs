#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SHA224_KEY_DERIVATION_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SHA224_KEY_DERIVATION_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct Sha224KeyDerivation: public MechanismBase
{
	Sha224KeyDerivation() noexcept;

	virtual ~Sha224KeyDerivation() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SHA224_KEY_DERIVATION_HPP