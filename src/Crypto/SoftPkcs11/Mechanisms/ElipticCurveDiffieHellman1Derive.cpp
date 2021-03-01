#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDiffieHellman1Derive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ElipticCurveDiffieHellman1Derive::ElipticCurveDiffieHellman1Derive() noexcept = default;
ElipticCurveDiffieHellman1Derive::~ElipticCurveDiffieHellman1Derive() noexcept = default;

pkcs11::enums::Mechanism ElipticCurveDiffieHellman1Derive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ECDH1_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

