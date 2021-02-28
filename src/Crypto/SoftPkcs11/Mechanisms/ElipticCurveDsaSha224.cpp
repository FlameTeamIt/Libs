#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDsaSha224.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ElipticCurveDsaSha224::ElipticCurveDsaSha224() noexcept = default;
ElipticCurveDsaSha224::~ElipticCurveDsaSha224() noexcept = default;

pkcs11::enums::Mechanism ElipticCurveDsaSha224::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ECDSA_SHA224;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

