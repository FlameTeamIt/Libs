#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KipMac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

KipMac::KipMac() noexcept = default;
KipMac::~KipMac() noexcept = default;

pkcs11::enums::Mechanism KipMac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::KIP_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

