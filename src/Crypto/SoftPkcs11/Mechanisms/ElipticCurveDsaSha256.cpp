#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDsaSha256.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ElipticCurveDsaSha256::ElipticCurveDsaSha256() noexcept = default;
ElipticCurveDsaSha256::~ElipticCurveDsaSha256() noexcept = default;

pkcs11::enums::Mechanism ElipticCurveDsaSha256::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ECDSA_SHA256;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

