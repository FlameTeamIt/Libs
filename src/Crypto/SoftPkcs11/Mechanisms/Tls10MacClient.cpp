#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls10MacClient.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Tls10MacClient::Tls10MacClient() noexcept = default;
Tls10MacClient::~Tls10MacClient() noexcept = default;

pkcs11::enums::Mechanism Tls10MacClient::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS10_MAC_CLIENT;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

