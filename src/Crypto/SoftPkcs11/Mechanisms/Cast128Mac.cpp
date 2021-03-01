#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast128Mac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast128Mac::Cast128Mac() noexcept = default;
Cast128Mac::~Cast128Mac() noexcept = default;

pkcs11::enums::Mechanism Cast128Mac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST128_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

