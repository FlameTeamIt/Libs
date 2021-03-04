#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Ssl3Md5Mac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Ssl3Md5Mac::Ssl3Md5Mac() noexcept = default;
Ssl3Md5Mac::~Ssl3Md5Mac() noexcept = default;

pkcs11::enums::Mechanism Ssl3Md5Mac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SSL3_MD5_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

