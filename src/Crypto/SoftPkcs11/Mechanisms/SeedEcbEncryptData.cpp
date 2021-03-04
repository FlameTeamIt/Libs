#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedEcbEncryptData.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SeedEcbEncryptData::SeedEcbEncryptData() noexcept = default;
SeedEcbEncryptData::~SeedEcbEncryptData() noexcept = default;

pkcs11::enums::Mechanism SeedEcbEncryptData::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SEED_ECB_ENCRYPT_DATA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

