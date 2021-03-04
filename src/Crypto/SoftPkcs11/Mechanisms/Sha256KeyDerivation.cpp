#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha256KeyDerivation.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha256KeyDerivation::Sha256KeyDerivation() noexcept = default;
Sha256KeyDerivation::~Sha256KeyDerivation() noexcept = default;

pkcs11::enums::Mechanism Sha256KeyDerivation::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA256_KEY_DERIVATION;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

