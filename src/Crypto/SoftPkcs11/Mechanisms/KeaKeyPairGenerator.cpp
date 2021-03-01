#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KeaKeyPairGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

KeaKeyPairGenerator::KeaKeyPairGenerator() noexcept = default;
KeaKeyPairGenerator::~KeaKeyPairGenerator() noexcept = default;

pkcs11::enums::Mechanism KeaKeyPairGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::KEA_KEY_PAIR_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

