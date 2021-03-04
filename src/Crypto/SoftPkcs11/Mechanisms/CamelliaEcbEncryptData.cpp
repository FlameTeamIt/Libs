#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaEcbEncryptData.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CamelliaEcbEncryptData::CamelliaEcbEncryptData() noexcept = default;
CamelliaEcbEncryptData::~CamelliaEcbEncryptData() noexcept = default;

pkcs11::enums::Mechanism CamelliaEcbEncryptData::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAMELLIA_ECB_ENCRYPT_DATA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

