#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gostr3410WithGostr3411.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Gostr3410WithGostr3411::Gostr3410WithGostr3411() noexcept = default;
Gostr3410WithGostr3411::~Gostr3410WithGostr3411() noexcept = default;

pkcs11::enums::Mechanism Gostr3410WithGostr3411::getType() const noexcept
{
	return pkcs11::enums::Mechanism::GOSTR3410_WITH_GOSTR3411;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

