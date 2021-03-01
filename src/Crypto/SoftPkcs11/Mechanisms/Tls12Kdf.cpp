#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls12Kdf.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Tls12Kdf::Tls12Kdf() noexcept = default;
Tls12Kdf::~Tls12Kdf() noexcept = default;

pkcs11::enums::Mechanism Tls12Kdf::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS12_KDF;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

