#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gostr3410KeyWrap.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Gostr3410KeyWrap::Gostr3410KeyWrap() noexcept = default;
Gostr3410KeyWrap::~Gostr3410KeyWrap() noexcept = default;

pkcs11::enums::Mechanism Gostr3410KeyWrap::getType() const noexcept
{
	return pkcs11::enums::Mechanism::GOSTR3410_KEY_WRAP;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

