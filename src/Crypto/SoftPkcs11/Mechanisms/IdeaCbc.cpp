#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/IdeaCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

IdeaCbc::IdeaCbc() noexcept = default;
IdeaCbc::~IdeaCbc() noexcept = default;

pkcs11::enums::Mechanism IdeaCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::IDEA_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

