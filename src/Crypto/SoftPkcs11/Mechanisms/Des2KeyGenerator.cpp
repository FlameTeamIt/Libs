#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des2KeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Des2KeyGenerator::Des2KeyGenerator() noexcept = default;
Des2KeyGenerator::~Des2KeyGenerator() noexcept = default;

pkcs11::enums::Mechanism Des2KeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES2_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

