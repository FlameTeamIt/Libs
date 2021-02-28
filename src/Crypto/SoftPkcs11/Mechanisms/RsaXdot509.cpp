#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaXdot509.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RsaXdot509::RsaXdot509() noexcept = default;
RsaXdot509::~RsaXdot509() noexcept = default;

pkcs11::enums::Mechanism RsaXdot509::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_X_509;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

