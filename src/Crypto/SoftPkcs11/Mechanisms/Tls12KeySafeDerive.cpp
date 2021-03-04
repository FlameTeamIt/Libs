#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Tls12KeySafeDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Tls12KeySafeDerive::Tls12KeySafeDerive() noexcept = default;
Tls12KeySafeDerive::~Tls12KeySafeDerive() noexcept = default;

pkcs11::enums::Mechanism Tls12KeySafeDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS12_KEY_SAFE_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

