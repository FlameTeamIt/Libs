#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/JuniperEcb128.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

JuniperEcb128::JuniperEcb128() noexcept = default;
JuniperEcb128::~JuniperEcb128() noexcept = default;

pkcs11::enums::Mechanism JuniperEcb128::getType() const noexcept
{
	return pkcs11::enums::Mechanism::JUNIPER_ECB128;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

