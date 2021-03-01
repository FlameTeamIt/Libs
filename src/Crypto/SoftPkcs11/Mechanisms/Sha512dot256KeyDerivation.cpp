#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot256KeyDerivation.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512dot256KeyDerivation::Sha512dot256KeyDerivation() noexcept = default;
Sha512dot256KeyDerivation::~Sha512dot256KeyDerivation() noexcept = default;

pkcs11::enums::Mechanism Sha512dot256KeyDerivation::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_256_KEY_DERIVATION;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

