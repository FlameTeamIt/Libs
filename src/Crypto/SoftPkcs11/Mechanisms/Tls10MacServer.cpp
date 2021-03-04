#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls10MacServer.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Tls10MacServer::Tls10MacServer() noexcept = default;
Tls10MacServer::~Tls10MacServer() noexcept = default;

pkcs11::enums::Mechanism Tls10MacServer::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS10_MAC_SERVER;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

