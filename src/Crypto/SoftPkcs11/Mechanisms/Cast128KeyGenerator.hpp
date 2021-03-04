#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_CAST128_KEY_GEN_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_CAST128_KEY_GEN_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct Cast128KeyGenerator: public MechanismBase
{
	Cast128KeyGenerator() noexcept;

	virtual ~Cast128KeyGenerator() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_CAST128_KEY_GEN_HPP
