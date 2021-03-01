#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha384RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha384RsaPkcs::Sha384RsaPkcs() noexcept = default;
Sha384RsaPkcs::~Sha384RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism Sha384RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA384_RSA_PKCS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

