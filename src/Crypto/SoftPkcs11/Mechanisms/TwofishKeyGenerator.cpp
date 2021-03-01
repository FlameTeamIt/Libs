#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TwofishKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

TwofishKeyGenerator::TwofishKeyGenerator() noexcept = default;
TwofishKeyGenerator::~TwofishKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism TwofishKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TWOFISH_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

