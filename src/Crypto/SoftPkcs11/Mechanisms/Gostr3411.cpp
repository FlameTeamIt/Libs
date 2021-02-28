#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gostr3411.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Gostr3411::Gostr3411() noexcept = default;
Gostr3411::~Gostr3411() noexcept = default;

pkcs11::enums::Mechanism Gostr3411::getType() const noexcept
{
	return pkcs11::enums::Mechanism::GOSTR3411;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

