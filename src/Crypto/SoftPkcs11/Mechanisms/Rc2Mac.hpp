#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RC2_MAC_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RC2_MAC_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct Rc2Mac: public MechanismBase
{
	Rc2Mac() noexcept;

	virtual ~Rc2Mac() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RC2_MAC_HPP
