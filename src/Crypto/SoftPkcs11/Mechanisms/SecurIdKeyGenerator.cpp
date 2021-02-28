#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SecurIdKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SecurIdKeyGenerator::SecurIdKeyGenerator() noexcept = default;
SecurIdKeyGenerator::~SecurIdKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism SecurIdKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SECURID_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

