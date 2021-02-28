#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512RsaPkcsPss.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512RsaPkcsPss::Sha512RsaPkcsPss() noexcept = default;
Sha512RsaPkcsPss::~Sha512RsaPkcsPss() noexcept = default;

pkcs11::enums::Mechanism Sha512RsaPkcsPss::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_RSA_PKCS_PSS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

