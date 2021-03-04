#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/BatonCounter.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

BatonCounter::BatonCounter() noexcept = default;
BatonCounter::~BatonCounter() noexcept = default;

pkcs11::enums::Mechanism BatonCounter::getType() const noexcept
{
	return pkcs11::enums::Mechanism::BATON_COUNTER;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

