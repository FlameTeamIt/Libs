#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SecurId.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

SecurId::SecurId() noexcept = default;
SecurId::~SecurId() noexcept = default;

pkcs11::enums::Mechanism SecurId::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SECURID;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

