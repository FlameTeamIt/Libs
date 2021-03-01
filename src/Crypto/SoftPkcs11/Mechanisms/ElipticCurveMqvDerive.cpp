#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveMqvDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ElipticCurveMqvDerive::ElipticCurveMqvDerive() noexcept = default;
ElipticCurveMqvDerive::~ElipticCurveMqvDerive() noexcept = default;

pkcs11::enums::Mechanism ElipticCurveMqvDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ECMQV_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

