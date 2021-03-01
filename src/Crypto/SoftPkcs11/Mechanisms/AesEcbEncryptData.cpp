#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesEcbEncryptData.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesEcbEncryptData::AesEcbEncryptData() noexcept = default;
AesEcbEncryptData::~AesEcbEncryptData() noexcept = default;

pkcs11::enums::Mechanism AesEcbEncryptData::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_ECB_ENCRYPT_DATA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

