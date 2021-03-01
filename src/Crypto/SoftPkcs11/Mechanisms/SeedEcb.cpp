#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedEcb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SeedEcb::SeedEcb() noexcept = default;
SeedEcb::~SeedEcb() noexcept = default;

pkcs11::enums::Mechanism SeedEcb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SEED_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

