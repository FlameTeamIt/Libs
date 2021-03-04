#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/GenericSecretKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

GenericSecretKeyGenerator::GenericSecretKeyGenerator() noexcept = default;
GenericSecretKeyGenerator::~GenericSecretKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism GenericSecretKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::GENERIC_SECRET_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

