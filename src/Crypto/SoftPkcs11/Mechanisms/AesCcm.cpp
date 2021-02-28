#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCcm.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesCcm::AesCcm() noexcept = default;
AesCcm::~AesCcm() noexcept = default;

pkcs11::enums::Mechanism AesCcm::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_CCM;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

