#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_PBE_SHA1_RC4_128_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_PBE_SHA1_RC4_128_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct PbeSha1Rc4dot128: public MechanismBase
{
	PbeSha1Rc4dot128() noexcept;

	virtual ~PbeSha1Rc4dot128() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_PBE_SHA1_RC4_128_HPP
