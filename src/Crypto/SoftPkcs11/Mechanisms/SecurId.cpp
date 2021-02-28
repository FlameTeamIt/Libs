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

pkcs11::structs::MechanismInfo SecurId::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info = MechanismBase::getInfo();
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::SIGN
			& pkcs11::enums::MechanismFlags::VERIFY
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

