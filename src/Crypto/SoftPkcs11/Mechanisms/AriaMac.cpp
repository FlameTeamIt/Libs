#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaMac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AriaMac::AriaMac() noexcept = default;
AriaMac::~AriaMac() noexcept = default;

pkcs11::enums::Mechanism AriaMac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ARIA_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

