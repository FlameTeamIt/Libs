#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/TwofishCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

TwofishCbc::TwofishCbc() noexcept = default;
TwofishCbc::~TwofishCbc() noexcept = default;

pkcs11::enums::Mechanism TwofishCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::TWOFISH_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

