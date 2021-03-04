#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BatonEcb96.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

BatonEcb96::BatonEcb96() noexcept = default;
BatonEcb96::~BatonEcb96() noexcept = default;

pkcs11::enums::Mechanism BatonEcb96::getType() const noexcept
{
	return pkcs11::enums::Mechanism::BATON_ECB96;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

