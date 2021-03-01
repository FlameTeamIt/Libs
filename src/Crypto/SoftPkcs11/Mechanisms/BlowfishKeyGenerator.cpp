#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BlowfishKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

BlowfishKeyGenerator::BlowfishKeyGenerator() noexcept = default;
BlowfishKeyGenerator::~BlowfishKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism BlowfishKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::BLOWFISH_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

