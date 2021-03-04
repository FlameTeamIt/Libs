#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3CbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Des3CbcPad::Des3CbcPad() noexcept = default;
Des3CbcPad::~Des3CbcPad() noexcept = default;

pkcs11::enums::Mechanism Des3CbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES3_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

