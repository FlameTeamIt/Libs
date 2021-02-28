#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaPkcsOaepTpm11.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RsaPkcsOaepTpm11::RsaPkcsOaepTpm11() noexcept = default;
RsaPkcsOaepTpm11::~RsaPkcsOaepTpm11() noexcept = default;

pkcs11::enums::Mechanism RsaPkcsOaepTpm11::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_PKCS_OAEP_TPM_1_1;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

