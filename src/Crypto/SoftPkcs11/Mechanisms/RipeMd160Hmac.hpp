#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RIPEMD160_HMAC_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RIPEMD160_HMAC_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct RipeMd160Hmac: public MechanismBase
{
	RipeMd160Hmac() noexcept;

	virtual ~RipeMd160Hmac() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RIPEMD160_HMAC_HPP
