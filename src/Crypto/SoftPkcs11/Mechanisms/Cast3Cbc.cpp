#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast3Cbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast3Cbc::Cast3Cbc() noexcept = default;
Cast3Cbc::~Cast3Cbc() noexcept = default;

pkcs11::enums::Mechanism Cast3Cbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST3_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

