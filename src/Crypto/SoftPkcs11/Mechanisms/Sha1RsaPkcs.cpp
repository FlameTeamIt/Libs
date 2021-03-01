#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha1RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha1RsaPkcs::Sha1RsaPkcs() noexcept = default;
Sha1RsaPkcs::~Sha1RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism Sha1RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA1_RSA_PKCS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

