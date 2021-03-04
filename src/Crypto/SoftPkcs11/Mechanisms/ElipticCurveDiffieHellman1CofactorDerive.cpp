#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDiffieHellman1CofactorDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ElipticCurveDiffieHellman1CofactorDerive::ElipticCurveDiffieHellman1CofactorDerive() noexcept = default;
ElipticCurveDiffieHellman1CofactorDerive::~ElipticCurveDiffieHellman1CofactorDerive() noexcept = default;

pkcs11::enums::Mechanism ElipticCurveDiffieHellman1CofactorDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ECDH1_COFACTOR_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

