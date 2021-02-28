#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/IdeaEcb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

IdeaEcb::IdeaEcb() noexcept = default;
IdeaEcb::~IdeaEcb() noexcept = default;

pkcs11::enums::Mechanism IdeaEcb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::IDEA_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

