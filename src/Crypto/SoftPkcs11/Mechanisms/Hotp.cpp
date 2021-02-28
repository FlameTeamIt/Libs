#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Hotp.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Hotp::Hotp() noexcept = default;
Hotp::~Hotp() noexcept = default;

pkcs11::enums::Mechanism Hotp::getType() const noexcept
{
	return pkcs11::enums::Mechanism::HOTP;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

