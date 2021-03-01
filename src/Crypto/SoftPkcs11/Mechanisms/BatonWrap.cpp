#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BatonWrap.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

BatonWrap::BatonWrap() noexcept = default;
BatonWrap::~BatonWrap() noexcept = default;

pkcs11::enums::Mechanism BatonWrap::getType() const noexcept
{
	return pkcs11::enums::Mechanism::BATON_WRAP;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

