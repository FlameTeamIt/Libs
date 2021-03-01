#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaPkcsTpm11.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RsaPkcsTpm11::RsaPkcsTpm11() noexcept = default;
RsaPkcsTpm11::~RsaPkcsTpm11() noexcept = default;

pkcs11::enums::Mechanism RsaPkcsTpm11::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_PKCS_TPM_1_1;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

