#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha256RsaPkcsPss.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha256RsaPkcsPss::Sha256RsaPkcsPss() noexcept = default;
Sha256RsaPkcsPss::~Sha256RsaPkcsPss() noexcept = default;

pkcs11::enums::Mechanism Sha256RsaPkcsPss::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA256_RSA_PKCS_PSS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

