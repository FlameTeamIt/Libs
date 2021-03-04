#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesEcbEncryptData.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DesEcbEncryptData::DesEcbEncryptData() noexcept = default;
DesEcbEncryptData::~DesEcbEncryptData() noexcept = default;

pkcs11::enums::Mechanism DesEcbEncryptData::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES_ECB_ENCRYPT_DATA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

