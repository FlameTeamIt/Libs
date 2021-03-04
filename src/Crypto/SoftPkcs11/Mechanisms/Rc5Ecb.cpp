#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rc5Ecb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rc5Ecb::Rc5Ecb() noexcept = default;
Rc5Ecb::~Rc5Ecb() noexcept = default;

pkcs11::enums::Mechanism Rc5Ecb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RC5_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

