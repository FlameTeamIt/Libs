#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512KeyDerivation.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512KeyDerivation::Sha512KeyDerivation() noexcept = default;
Sha512KeyDerivation::~Sha512KeyDerivation() noexcept = default;

pkcs11::enums::Mechanism Sha512KeyDerivation::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_KEY_DERIVATION;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

