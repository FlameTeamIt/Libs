#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Cast3CbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Cast3CbcPad::Cast3CbcPad() noexcept = default;
Cast3CbcPad::~Cast3CbcPad() noexcept = default;

pkcs11::enums::Mechanism Cast3CbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST3_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

