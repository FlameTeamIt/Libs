#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TlsMac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

TlsMac::TlsMac() noexcept = default;
TlsMac::~TlsMac() noexcept = default;

pkcs11::enums::Mechanism TlsMac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

