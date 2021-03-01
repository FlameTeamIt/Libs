#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TlsPrf.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

TlsPrf::TlsPrf() noexcept = default;
TlsPrf::~TlsPrf() noexcept = default;

pkcs11::enums::Mechanism TlsPrf::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TLS_PRF;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

