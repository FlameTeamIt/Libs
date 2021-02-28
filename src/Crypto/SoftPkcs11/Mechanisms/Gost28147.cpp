#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gost28147.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Gost28147::Gost28147() noexcept = default;
Gost28147::~Gost28147() noexcept = default;

pkcs11::enums::Mechanism Gost28147::getType() const noexcept
{
	return pkcs11::enums::Mechanism::GOST28147;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

