#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BatonCbc128.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

BatonCbc128::BatonCbc128() noexcept = default;
BatonCbc128::~BatonCbc128() noexcept = default;

pkcs11::enums::Mechanism BatonCbc128::getType() const noexcept
{
	return pkcs11::enums::Mechanism::BATON_CBC128;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

