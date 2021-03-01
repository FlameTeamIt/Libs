#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_JUNIPER_ECB128_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_JUNIPER_ECB128_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct JuniperEcb128: public MechanismBase
{
	JuniperEcb128() noexcept;

	virtual ~JuniperEcb128() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_JUNIPER_ECB128_HPP
