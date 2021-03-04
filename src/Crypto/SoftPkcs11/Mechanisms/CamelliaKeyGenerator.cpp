#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CamelliaKeyGenerator::CamelliaKeyGenerator() noexcept = default;
CamelliaKeyGenerator::~CamelliaKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism CamelliaKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAMELLIA_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

