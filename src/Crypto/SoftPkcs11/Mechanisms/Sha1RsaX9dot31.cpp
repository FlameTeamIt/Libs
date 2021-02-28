#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha1RsaX9dot31.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha1RsaX9dot31::Sha1RsaX9dot31() noexcept = default;
Sha1RsaX9dot31::~Sha1RsaX9dot31() noexcept = default;

pkcs11::enums::Mechanism Sha1RsaX9dot31::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA1_RSA_X9_31;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

