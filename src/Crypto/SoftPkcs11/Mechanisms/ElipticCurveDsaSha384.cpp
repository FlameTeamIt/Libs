#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDsaSha384.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ElipticCurveDsaSha384::ElipticCurveDsaSha384() noexcept = default;
ElipticCurveDsaSha384::~ElipticCurveDsaSha384() noexcept = default;

pkcs11::enums::Mechanism ElipticCurveDsaSha384::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ECDSA_SHA384;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

