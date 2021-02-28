#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedMacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SeedMacGeneral::SeedMacGeneral() noexcept = default;
SeedMacGeneral::~SeedMacGeneral() noexcept = default;

pkcs11::enums::Mechanism SeedMacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SEED_MAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

