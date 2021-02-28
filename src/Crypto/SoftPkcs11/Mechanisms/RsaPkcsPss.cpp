#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaPkcsPss.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RsaPkcsPss::RsaPkcsPss() noexcept = default;
RsaPkcsPss::~RsaPkcsPss() noexcept = default;

pkcs11::enums::Mechanism RsaPkcsPss::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_PKCS_PSS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

