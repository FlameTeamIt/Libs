#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gostr3410.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Gostr3410::Gostr3410() noexcept = default;
Gostr3410::~Gostr3410() noexcept = default;

pkcs11::enums::Mechanism Gostr3410::getType() const noexcept
{
	return pkcs11::enums::Mechanism::GOSTR3410;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

