#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot224KeyDerivation.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512dot224KeyDerivation::Sha512dot224KeyDerivation() noexcept = default;
Sha512dot224KeyDerivation::~Sha512dot224KeyDerivation() noexcept = default;

pkcs11::enums::Mechanism Sha512dot224KeyDerivation::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_224_KEY_DERIVATION;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

