#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc2Cbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rc2Cbc::Rc2Cbc() noexcept = default;
Rc2Cbc::~Rc2Cbc() noexcept = default;

pkcs11::enums::Mechanism Rc2Cbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RC2_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

