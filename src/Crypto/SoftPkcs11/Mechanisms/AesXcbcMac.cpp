#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesXcbcMac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesXcbcMac::AesXcbcMac() noexcept = default;
AesXcbcMac::~AesXcbcMac() noexcept = default;

pkcs11::enums::Mechanism AesXcbcMac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_XCBC_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

