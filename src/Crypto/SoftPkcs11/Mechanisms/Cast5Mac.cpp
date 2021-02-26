#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast5Mac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast5Mac::Cast5Mac() noexcept = default;

Cast5Mac::~Cast5Mac() noexcept = default;

pkcs11::enums::Mechanism
Cast5Mac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST5_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

