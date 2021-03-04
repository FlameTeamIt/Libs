#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md2.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Md2::Md2() noexcept = default;
Md2::~Md2() noexcept = default;

pkcs11::enums::Mechanism Md2::getType() const noexcept
{
	return pkcs11::enums::Mechanism::MD2;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

