#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_GOSTR3411_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_GOSTR3411_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct Gostr3411: public MechanismBase
{
	Gostr3411() noexcept;

	virtual ~Gostr3411() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_GOSTR3411_HPP
