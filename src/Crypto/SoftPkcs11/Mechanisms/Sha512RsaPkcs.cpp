#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512RsaPkcs::Sha512RsaPkcs() noexcept = default;
Sha512RsaPkcs::~Sha512RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism Sha512RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_RSA_PKCS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

