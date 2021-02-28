#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Ssl3Sha1Mac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Ssl3Sha1Mac::Ssl3Sha1Mac() noexcept = default;
Ssl3Sha1Mac::~Ssl3Sha1Mac() noexcept = default;

pkcs11::enums::Mechanism Ssl3Sha1Mac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SSL3_SHA1_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

