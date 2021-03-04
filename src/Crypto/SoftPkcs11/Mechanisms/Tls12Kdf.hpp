#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_TLS12_KDF_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_TLS12_KDF_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct Tls12Kdf: public MechanismBase
{
	Tls12Kdf() noexcept;

	virtual ~Tls12Kdf() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_TLS12_KDF_HPP
