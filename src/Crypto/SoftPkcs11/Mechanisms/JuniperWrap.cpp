#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/JuniperWrap.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

JuniperWrap::JuniperWrap() noexcept = default;
JuniperWrap::~JuniperWrap() noexcept = default;

pkcs11::enums::Mechanism JuniperWrap::getType() const noexcept
{
	return pkcs11::enums::Mechanism::JUNIPER_WRAP;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

