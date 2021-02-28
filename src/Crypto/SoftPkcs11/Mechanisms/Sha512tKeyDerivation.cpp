#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512tKeyDerivation.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512tKeyDerivation::Sha512tKeyDerivation() noexcept = default;
Sha512tKeyDerivation::~Sha512tKeyDerivation() noexcept = default;

pkcs11::enums::Mechanism Sha512tKeyDerivation::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_T_KEY_DERIVATION;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

