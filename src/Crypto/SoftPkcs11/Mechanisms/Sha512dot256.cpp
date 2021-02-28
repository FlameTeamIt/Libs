#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot256.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512dot256::Sha512dot256() noexcept = default;
Sha512dot256::~Sha512dot256() noexcept = default;

pkcs11::enums::Mechanism Sha512dot256::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_256;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

