#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha1RsaPkcsPss.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha1RsaPkcsPss::Sha1RsaPkcsPss() noexcept = default;
Sha1RsaPkcsPss::~Sha1RsaPkcsPss() noexcept = default;

pkcs11::enums::Mechanism Sha1RsaPkcsPss::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA1_RSA_PKCS_PSS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

