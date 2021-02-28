#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCbcEncryptData.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesCbcEncryptData::AesCbcEncryptData() noexcept = default;
AesCbcEncryptData::~AesCbcEncryptData() noexcept = default;

pkcs11::enums::Mechanism AesCbcEncryptData::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_CBC_ENCRYPT_DATA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

