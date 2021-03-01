#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KeyWrapSetOaep.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

KeyWrapSetOaep::KeyWrapSetOaep() noexcept = default;
KeyWrapSetOaep::~KeyWrapSetOaep() noexcept = default;

pkcs11::enums::Mechanism KeyWrapSetOaep::getType() const noexcept
{
	return pkcs11::enums::Mechanism::KEY_WRAP_SET_OAEP;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

