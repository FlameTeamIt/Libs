#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaMacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AriaMacGeneral::AriaMacGeneral() noexcept = default;
AriaMacGeneral::~AriaMacGeneral() noexcept = default;

pkcs11::enums::Mechanism AriaMacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ARIA_MAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

