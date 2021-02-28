#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3CbcEncryptData.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Des3CbcEncryptData::Des3CbcEncryptData() noexcept = default;
Des3CbcEncryptData::~Des3CbcEncryptData() noexcept = default;

pkcs11::enums::Mechanism Des3CbcEncryptData::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES3_CBC_ENCRYPT_DATA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

