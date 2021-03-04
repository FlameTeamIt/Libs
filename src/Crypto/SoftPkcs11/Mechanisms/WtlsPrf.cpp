#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/WtlsPrf.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

WtlsPrf::WtlsPrf() noexcept = default;
WtlsPrf::~WtlsPrf() noexcept = default;

pkcs11::enums::Mechanism WtlsPrf::getType() const noexcept
{
	return pkcs11::enums::Mechanism::WTLS_PRF;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

