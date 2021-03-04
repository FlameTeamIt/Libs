#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SeedCbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SeedCbcPad::SeedCbcPad() noexcept = default;
SeedCbcPad::~SeedCbcPad() noexcept = default;

pkcs11::enums::Mechanism SeedCbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SEED_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

