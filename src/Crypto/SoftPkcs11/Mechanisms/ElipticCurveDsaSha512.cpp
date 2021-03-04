#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDsaSha512.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ElipticCurveDsaSha512::ElipticCurveDsaSha512() noexcept = default;
ElipticCurveDsaSha512::~ElipticCurveDsaSha512() noexcept = default;

pkcs11::enums::Mechanism ElipticCurveDsaSha512::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ECDSA_SHA512;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

