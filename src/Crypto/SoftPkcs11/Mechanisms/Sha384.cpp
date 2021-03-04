#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha384.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha384::Sha384() noexcept = default;
Sha384::~Sha384() noexcept = default;

pkcs11::enums::Mechanism Sha384::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA384;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

