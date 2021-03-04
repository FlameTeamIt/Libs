#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast128Cbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast128Cbc::Cast128Cbc() noexcept = default;
Cast128Cbc::~Cast128Cbc() noexcept = default;

pkcs11::enums::Mechanism Cast128Cbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST128_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

