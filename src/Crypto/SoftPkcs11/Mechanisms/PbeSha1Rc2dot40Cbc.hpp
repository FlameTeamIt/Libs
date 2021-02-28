#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_PBE_SHA1_RC2_40_CBC_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_PBE_SHA1_RC2_40_CBC_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct PbeSha1Rc2dot40Cbc: public MechanismBase
{
	PbeSha1Rc2dot40Cbc() noexcept;

	virtual ~PbeSha1Rc2dot40Cbc() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_PBE_SHA1_RC2_40_CBC_HPP
