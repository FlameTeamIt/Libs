#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaKeyPairGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DsaKeyPairGenerator::DsaKeyPairGenerator() noexcept = default;
DsaKeyPairGenerator::~DsaKeyPairGenerator() noexcept = default;

pkcs11::enums::Mechanism DsaKeyPairGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DSA_KEY_PAIR_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

