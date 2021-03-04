#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AriaCbc::AriaCbc() noexcept = default;
AriaCbc::~AriaCbc() noexcept = default;

pkcs11::enums::Mechanism AriaCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ARIA_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

