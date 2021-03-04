#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KipDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

KipDerive::KipDerive() noexcept = default;
KipDerive::~KipDerive() noexcept = default;

pkcs11::enums::Mechanism KipDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::KIP_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

