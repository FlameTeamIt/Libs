#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/JuniperKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

JuniperKeyGenerator::JuniperKeyGenerator() noexcept = default;
JuniperKeyGenerator::~JuniperKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism JuniperKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::JUNIPER_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

