#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/HotpKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

HotpKeyGenerator::HotpKeyGenerator() noexcept = default;
HotpKeyGenerator::~HotpKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism HotpKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::HOTP_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

