#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaCbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CamelliaCbcPad::CamelliaCbcPad() noexcept = default;
CamelliaCbcPad::~CamelliaCbcPad() noexcept = default;

pkcs11::enums::Mechanism CamelliaCbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAMELLIA_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

