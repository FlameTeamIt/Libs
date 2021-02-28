#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha1KeyDerivation.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha1KeyDerivation::Sha1KeyDerivation() noexcept = default;
Sha1KeyDerivation::~Sha1KeyDerivation() noexcept = default;

pkcs11::enums::Mechanism Sha1KeyDerivation::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA1_KEY_DERIVATION;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

