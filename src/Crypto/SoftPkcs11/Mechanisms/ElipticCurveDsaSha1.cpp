#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDsaSha1.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ElipticCurveDsaSha1::ElipticCurveDsaSha1() noexcept = default;
ElipticCurveDsaSha1::~ElipticCurveDsaSha1() noexcept = default;

pkcs11::enums::Mechanism ElipticCurveDsaSha1::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ECDSA_SHA1;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

