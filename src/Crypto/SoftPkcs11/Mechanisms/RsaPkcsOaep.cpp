#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaPkcsOaep.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RsaPkcsOaep::RsaPkcsOaep() noexcept = default;
RsaPkcsOaep::~RsaPkcsOaep() noexcept = default;

pkcs11::enums::Mechanism RsaPkcsOaep::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_PKCS_OAEP;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

