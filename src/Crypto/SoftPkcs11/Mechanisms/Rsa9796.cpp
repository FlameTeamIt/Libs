#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa9796.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Rsa9796::Rsa9796() noexcept = default;
Rsa9796::~Rsa9796() noexcept = default;

pkcs11::enums::Mechanism Rsa9796::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_9796;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

