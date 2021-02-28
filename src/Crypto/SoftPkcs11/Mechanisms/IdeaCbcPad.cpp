#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/IdeaCbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

IdeaCbcPad::IdeaCbcPad() noexcept = default;
IdeaCbcPad::~IdeaCbcPad() noexcept = default;

pkcs11::enums::Mechanism IdeaCbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::IDEA_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

