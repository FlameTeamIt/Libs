#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RSA_X9_31_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RSA_X9_31_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct RsaX9dot31: public MechanismBase
{
	RsaX9dot31() noexcept;

	virtual ~RsaX9dot31() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RSA_X9_31_HPP
