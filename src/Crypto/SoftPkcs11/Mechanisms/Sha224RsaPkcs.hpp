#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SHA224_RSA_PKCS_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SHA224_RSA_PKCS_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct Sha224RsaPkcs: public MechanismBase
{
	Sha224RsaPkcs() noexcept;

	virtual ~Sha224RsaPkcs() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_SHA224_RSA_PKCS_HPP
