#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha384KeyDerivation.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha384KeyDerivation::Sha384KeyDerivation() noexcept = default;
Sha384KeyDerivation::~Sha384KeyDerivation() noexcept = default;

pkcs11::enums::Mechanism Sha384KeyDerivation::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA384_KEY_DERIVATION;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

