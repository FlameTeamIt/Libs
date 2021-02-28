#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_TLS10_MAC_SERVER_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_TLS10_MAC_SERVER_HPP

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

struct Tls10MacServer: public MechanismBase
{
	Tls10MacServer() noexcept;

	virtual ~Tls10MacServer() noexcept override;

	virtual pkcs11::enums::Mechanism getType() const noexcept override;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_TLS10_MAC_SERVER_HPP
