#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/IdeaMac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

IdeaMac::IdeaMac() noexcept = default;
IdeaMac::~IdeaMac() noexcept = default;

pkcs11::enums::Mechanism IdeaMac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::IDEA_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

