#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaEcb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AriaEcb::AriaEcb() noexcept = default;
AriaEcb::~AriaEcb() noexcept = default;

pkcs11::enums::Mechanism AriaEcb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ARIA_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

