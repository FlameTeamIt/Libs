#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDH1CofactorDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ElipticCurveDH1CofactorDerive::ElipticCurveDH1CofactorDerive() noexcept = default;

ElipticCurveDH1CofactorDerive::~ElipticCurveDH1CofactorDerive() noexcept = default;

pkcs11::enums::Mechanism
ElipticCurveDH1CofactorDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ECDH1_COFACTOR_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

