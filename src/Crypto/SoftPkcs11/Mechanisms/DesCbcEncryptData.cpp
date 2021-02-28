#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesCbcEncryptData.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DesCbcEncryptData::DesCbcEncryptData() noexcept = default;
DesCbcEncryptData::~DesCbcEncryptData() noexcept = default;

pkcs11::enums::Mechanism DesCbcEncryptData::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES_CBC_ENCRYPT_DATA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

