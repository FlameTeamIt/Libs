#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KeyWrapLynks.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

KeyWrapLynks::KeyWrapLynks() noexcept = default;
KeyWrapLynks::~KeyWrapLynks() noexcept = default;

pkcs11::enums::Mechanism KeyWrapLynks::getType() const noexcept
{
	return pkcs11::enums::Mechanism::KEY_WRAP_LYNKS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

