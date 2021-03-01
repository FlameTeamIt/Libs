#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3KeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Des3KeyGenerator::Des3KeyGenerator() noexcept = default;
Des3KeyGenerator::~Des3KeyGenerator() noexcept = default;

pkcs11::enums::Mechanism Des3KeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES3_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

