#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedCbcEncryptData.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SeedCbcEncryptData::SeedCbcEncryptData() noexcept = default;
SeedCbcEncryptData::~SeedCbcEncryptData() noexcept = default;

pkcs11::enums::Mechanism SeedCbcEncryptData::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SEED_CBC_ENCRYPT_DATA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

