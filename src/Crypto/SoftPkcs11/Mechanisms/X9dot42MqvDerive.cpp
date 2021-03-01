#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/X9dot42MqvDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

X9dot42MqvDerive::X9dot42MqvDerive() noexcept = default;
X9dot42MqvDerive::~X9dot42MqvDerive() noexcept = default;

pkcs11::enums::Mechanism X9dot42MqvDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::X9_42_MQV_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

