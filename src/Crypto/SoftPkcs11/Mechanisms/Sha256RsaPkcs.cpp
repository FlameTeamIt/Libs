#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha256RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha256RsaPkcs::Sha256RsaPkcs() noexcept = default;
Sha256RsaPkcs::~Sha256RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism Sha256RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA256_RSA_PKCS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

