#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/JuniperCounter.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

JuniperCounter::JuniperCounter() noexcept = default;
JuniperCounter::~JuniperCounter() noexcept = default;

pkcs11::enums::Mechanism JuniperCounter::getType() const noexcept
{
	return pkcs11::enums::Mechanism::JUNIPER_COUNTER;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

