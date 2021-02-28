#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_GOST28147_KEY_GEN_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_GOST28147_KEY_GEN_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct Gost28147KeyGenerator: public MechanismBase
{
	Gost28147KeyGenerator() noexcept;

	virtual ~Gost28147KeyGenerator() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_GOST28147_KEY_GEN_HPP
