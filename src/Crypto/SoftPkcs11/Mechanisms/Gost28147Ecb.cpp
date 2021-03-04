#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Gost28147Ecb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Gost28147Ecb::Gost28147Ecb() noexcept = default;
Gost28147Ecb::~Gost28147Ecb() noexcept = default;

pkcs11::enums::Mechanism Gost28147Ecb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::GOST28147_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

