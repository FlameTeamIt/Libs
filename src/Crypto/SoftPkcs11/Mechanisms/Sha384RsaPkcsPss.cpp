#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha384RsaPkcsPss.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha384RsaPkcsPss::Sha384RsaPkcsPss() noexcept = default;
Sha384RsaPkcsPss::~Sha384RsaPkcsPss() noexcept = default;

pkcs11::enums::Mechanism Sha384RsaPkcsPss::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA384_RSA_PKCS_PSS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

