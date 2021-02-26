#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast5Ecb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast5Ecb::Cast5Ecb() noexcept = default;

Cast5Ecb::~Cast5Ecb() noexcept = default;

pkcs11::enums::Mechanism
Cast5Ecb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST5_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

