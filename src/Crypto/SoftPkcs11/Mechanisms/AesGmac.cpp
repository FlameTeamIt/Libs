#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesGmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesGmac::AesGmac() noexcept = default;
AesGmac::~AesGmac() noexcept = default;

pkcs11::enums::Mechanism AesGmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_GMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

