#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md5KeyDerivation.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Md5KeyDerivation::Md5KeyDerivation() noexcept = default;
Md5KeyDerivation::~Md5KeyDerivation() noexcept = default;

pkcs11::enums::Mechanism Md5KeyDerivation::getType() const noexcept
{
	return pkcs11::enums::Mechanism::MD5_KEY_DERIVATION;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

