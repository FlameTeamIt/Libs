#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BatonEcb128.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

BatonEcb128::BatonEcb128() noexcept = default;
BatonEcb128::~BatonEcb128() noexcept = default;

pkcs11::enums::Mechanism BatonEcb128::getType() const noexcept
{
	return pkcs11::enums::Mechanism::BATON_ECB128;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

