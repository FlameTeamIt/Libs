#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesXcbcMac96.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesXcbcMac96::AesXcbcMac96() noexcept = default;
AesXcbcMac96::~AesXcbcMac96() noexcept = default;

pkcs11::enums::Mechanism AesXcbcMac96::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_XCBC_MAC_96;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

