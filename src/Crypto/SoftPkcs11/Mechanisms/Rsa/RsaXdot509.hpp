#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RSA_X_509_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RSA_X_509_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct RsaXdot509: public MechanismBase
{
	RsaXdot509() noexcept;

	virtual ~RsaXdot509() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;

	virtual pkcs11::structs::MechanismInfo getInfo() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_RSA_X_509_HPP
