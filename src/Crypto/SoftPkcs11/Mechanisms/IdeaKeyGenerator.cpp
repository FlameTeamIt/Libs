#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/IdeaKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

IdeaKeyGenerator::IdeaKeyGenerator() noexcept = default;
IdeaKeyGenerator::~IdeaKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism IdeaKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::IDEA_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

