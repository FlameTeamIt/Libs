#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_TLS10_MAC_CLIENT_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_TLS10_MAC_CLIENT_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct Tls10MacClient: public MechanismBase
{
	Tls10MacClient() noexcept;

	virtual ~Tls10MacClient() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_TLS10_MAC_CLIENT_HPP
