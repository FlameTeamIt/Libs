#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaEcbEncryptData.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AriaEcbEncryptData::AriaEcbEncryptData() noexcept = default;
AriaEcbEncryptData::~AriaEcbEncryptData() noexcept = default;

pkcs11::enums::Mechanism AriaEcbEncryptData::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ARIA_ECB_ENCRYPT_DATA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

