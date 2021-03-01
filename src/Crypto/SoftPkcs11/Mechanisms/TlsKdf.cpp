#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TlsKdf.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

TlsKdf::TlsKdf() noexcept = default;
TlsKdf::~TlsKdf() noexcept = default;

pkcs11::enums::Mechanism TlsKdf::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS_KDF;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

