#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_CAST3_CBC_PAD_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_CAST3_CBC_PAD_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct Cast3CbcPad: public MechanismBase
{
	Cast3CbcPad() noexcept;

	virtual ~Cast3CbcPad() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_CAST3_CBC_PAD_HPP
