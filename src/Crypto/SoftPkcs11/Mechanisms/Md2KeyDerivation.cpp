#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md2KeyDerivation.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Md2KeyDerivation::Md2KeyDerivation() noexcept = default;
Md2KeyDerivation::~Md2KeyDerivation() noexcept = default;

pkcs11::enums::Mechanism Md2KeyDerivation::getType() const noexcept
{
	return pkcs11::enums::Mechanism::MD2_KEY_DERIVATION;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

