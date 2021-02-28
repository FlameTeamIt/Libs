#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BlowfishCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

BlowfishCbc::BlowfishCbc() noexcept = default;
BlowfishCbc::~BlowfishCbc() noexcept = default;

pkcs11::enums::Mechanism BlowfishCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::BLOWFISH_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

