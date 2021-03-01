#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512::Sha512() noexcept = default;
Sha512::~Sha512() noexcept = default;

pkcs11::enums::Mechanism Sha512::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

