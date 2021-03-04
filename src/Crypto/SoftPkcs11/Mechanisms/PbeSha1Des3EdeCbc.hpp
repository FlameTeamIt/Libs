#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_PBE_SHA1_DES3_EDE_CBC_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_PBE_SHA1_DES3_EDE_CBC_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct PbeSha1Des3EdeCbc: public MechanismBase
{
	PbeSha1Des3EdeCbc() noexcept;

	virtual ~PbeSha1Des3EdeCbc() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_PBE_SHA1_DES3_EDE_CBC_HPP
