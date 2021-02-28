#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_AES_CFB64_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_AES_CFB64_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct AesCfb64: public MechanismBase
{
	AesCfb64() noexcept;

	virtual ~AesCfb64() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_AES_CFB64_HPP
