#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast3Ecb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast3Ecb::Cast3Ecb() noexcept = default;
Cast3Ecb::~Cast3Ecb() noexcept = default;

pkcs11::enums::Mechanism Cast3Ecb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST3_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

