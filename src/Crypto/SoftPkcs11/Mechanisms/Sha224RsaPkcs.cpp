#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha224RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha224RsaPkcs::Sha224RsaPkcs() noexcept = default;
Sha224RsaPkcs::~Sha224RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism Sha224RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA224_RSA_PKCS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

