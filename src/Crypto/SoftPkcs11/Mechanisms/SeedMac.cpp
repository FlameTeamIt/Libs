#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedMac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SeedMac::SeedMac() noexcept = default;
SeedMac::~SeedMac() noexcept = default;

pkcs11::enums::Mechanism SeedMac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SEED_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

