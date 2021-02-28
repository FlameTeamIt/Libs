#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Dsa.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Dsa::Dsa() noexcept = default;
Dsa::~Dsa() noexcept = default;

pkcs11::enums::Mechanism Dsa::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DSA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

