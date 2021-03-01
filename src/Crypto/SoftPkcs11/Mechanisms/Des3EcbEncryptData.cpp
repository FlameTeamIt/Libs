#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3EcbEncryptData.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Des3EcbEncryptData::Des3EcbEncryptData() noexcept = default;
Des3EcbEncryptData::~Des3EcbEncryptData() noexcept = default;

pkcs11::enums::Mechanism Des3EcbEncryptData::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES3_ECB_ENCRYPT_DATA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

