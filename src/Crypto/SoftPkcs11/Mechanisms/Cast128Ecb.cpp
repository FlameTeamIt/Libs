#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast128Ecb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast128Ecb::Cast128Ecb() noexcept = default;
Cast128Ecb::~Cast128Ecb() noexcept = default;

pkcs11::enums::Mechanism Cast128Ecb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST128_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

