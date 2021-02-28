#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesEcb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesEcb::AesEcb() noexcept = default;
AesEcb::~AesEcb() noexcept = default;

pkcs11::enums::Mechanism AesEcb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

