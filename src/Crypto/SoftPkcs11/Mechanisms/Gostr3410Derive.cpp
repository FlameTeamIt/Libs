#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gostr3410Derive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Gostr3410Derive::Gostr3410Derive() noexcept = default;
Gostr3410Derive::~Gostr3410Derive() noexcept = default;

pkcs11::enums::Mechanism Gostr3410Derive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::GOSTR3410_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

