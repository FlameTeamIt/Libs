#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesKeyGenerator::AesKeyGenerator() noexcept = default;
AesKeyGenerator::~AesKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism AesKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

