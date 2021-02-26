#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast5Cbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast5Cbc::Cast5Cbc() noexcept = default;

Cast5Cbc::~Cast5Cbc() noexcept = default;

pkcs11::enums::Mechanism
Cast5Cbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST5_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

