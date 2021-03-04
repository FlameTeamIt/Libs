#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MD5_KEY_DERIVATION_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MD5_KEY_DERIVATION_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct Md5KeyDerivation: public MechanismBase
{
	Md5KeyDerivation() noexcept;

	virtual ~Md5KeyDerivation() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MD5_KEY_DERIVATION_HPP
