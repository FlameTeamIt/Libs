#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/JuniperCbc128.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

JuniperCbc128::JuniperCbc128() noexcept = default;
JuniperCbc128::~JuniperCbc128() noexcept = default;

pkcs11::enums::Mechanism JuniperCbc128::getType() const noexcept
{
	return pkcs11::enums::Mechanism::JUNIPER_CBC128;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

