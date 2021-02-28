#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha256.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha256::Sha256() noexcept = default;
Sha256::~Sha256() noexcept = default;

pkcs11::enums::Mechanism Sha256::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA256;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

