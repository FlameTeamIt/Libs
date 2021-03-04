#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CastCbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CastCbcPad::CastCbcPad() noexcept = default;
CastCbcPad::~CastCbcPad() noexcept = default;

pkcs11::enums::Mechanism CastCbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

