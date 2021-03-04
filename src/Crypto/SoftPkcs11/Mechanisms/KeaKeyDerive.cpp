#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KeaKeyDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

KeaKeyDerive::KeaKeyDerive() noexcept = default;
KeaKeyDerive::~KeaKeyDerive() noexcept = default;

pkcs11::enums::Mechanism KeaKeyDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::KEA_KEY_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

