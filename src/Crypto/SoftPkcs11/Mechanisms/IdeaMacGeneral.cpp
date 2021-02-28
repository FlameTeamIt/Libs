#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/IdeaMacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

IdeaMacGeneral::IdeaMacGeneral() noexcept = default;
IdeaMacGeneral::~IdeaMacGeneral() noexcept = default;

pkcs11::enums::Mechanism IdeaMacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::IDEA_MAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

