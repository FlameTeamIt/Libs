#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha224RsaPkcsPss.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha224RsaPkcsPss::Sha224RsaPkcsPss() noexcept = default;
Sha224RsaPkcsPss::~Sha224RsaPkcsPss() noexcept = default;

pkcs11::enums::Mechanism Sha224RsaPkcsPss::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA224_RSA_PKCS_PSS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

