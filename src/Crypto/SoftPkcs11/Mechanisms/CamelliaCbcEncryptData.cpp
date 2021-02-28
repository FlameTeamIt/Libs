#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaCbcEncryptData.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CamelliaCbcEncryptData::CamelliaCbcEncryptData() noexcept = default;
CamelliaCbcEncryptData::~CamelliaCbcEncryptData() noexcept = default;

pkcs11::enums::Mechanism CamelliaCbcEncryptData::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAMELLIA_CBC_ENCRYPT_DATA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

