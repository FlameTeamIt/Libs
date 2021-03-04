#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha224KeyDerivation.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha224KeyDerivation::Sha224KeyDerivation() noexcept = default;
Sha224KeyDerivation::~Sha224KeyDerivation() noexcept = default;

pkcs11::enums::Mechanism Sha224KeyDerivation::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA224_KEY_DERIVATION;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

