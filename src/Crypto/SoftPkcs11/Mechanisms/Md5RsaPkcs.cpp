#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md5RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Md5RsaPkcs::Md5RsaPkcs() noexcept = default;
Md5RsaPkcs::~Md5RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism Md5RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::MD5_RSA_PKCS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

