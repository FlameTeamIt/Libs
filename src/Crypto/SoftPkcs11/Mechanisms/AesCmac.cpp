#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesCmac::AesCmac() noexcept = default;
AesCmac::~AesCmac() noexcept = default;

pkcs11::enums::Mechanism AesCmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_CMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

