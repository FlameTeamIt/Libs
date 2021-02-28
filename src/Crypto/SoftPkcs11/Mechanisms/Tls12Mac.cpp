#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls12Mac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Tls12Mac::Tls12Mac() noexcept = default;
Tls12Mac::~Tls12Mac() noexcept = default;

pkcs11::enums::Mechanism Tls12Mac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS12_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

