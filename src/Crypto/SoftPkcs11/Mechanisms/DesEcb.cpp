#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesEcb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DesEcb::DesEcb() noexcept = default;
DesEcb::~DesEcb() noexcept = default;

pkcs11::enums::Mechanism DesEcb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

