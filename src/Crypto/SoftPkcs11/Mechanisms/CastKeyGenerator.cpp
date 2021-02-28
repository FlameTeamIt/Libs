#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CastKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CastKeyGenerator::CastKeyGenerator() noexcept = default;
CastKeyGenerator::~CastKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism CastKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

