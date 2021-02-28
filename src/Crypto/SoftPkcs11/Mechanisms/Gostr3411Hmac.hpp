#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_GOSTR3411_HMAC_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_GOSTR3411_HMAC_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct Gostr3411Hmac: public MechanismBase
{
	Gostr3411Hmac() noexcept;

	virtual ~Gostr3411Hmac() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_GOSTR3411_HMAC_HPP
