#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SeedCbc::SeedCbc() noexcept = default;
SeedCbc::~SeedCbc() noexcept = default;

pkcs11::enums::Mechanism SeedCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SEED_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

