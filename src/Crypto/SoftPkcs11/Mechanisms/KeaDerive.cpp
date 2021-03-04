#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KeaDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

KeaDerive::KeaDerive() noexcept = default;
KeaDerive::~KeaDerive() noexcept = default;

pkcs11::enums::Mechanism KeaDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::KEA_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

