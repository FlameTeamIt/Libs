#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast3Mac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast3Mac::Cast3Mac() noexcept = default;
Cast3Mac::~Cast3Mac() noexcept = default;

pkcs11::enums::Mechanism Cast3Mac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST3_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

