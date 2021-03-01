#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc2Ecb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rc2Ecb::Rc2Ecb() noexcept = default;
Rc2Ecb::~Rc2Ecb() noexcept = default;

pkcs11::enums::Mechanism Rc2Ecb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RC2_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

