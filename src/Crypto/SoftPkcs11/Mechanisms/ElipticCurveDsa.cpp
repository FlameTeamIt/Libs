#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDsa.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ElipticCurveDsa::ElipticCurveDsa() noexcept = default;
ElipticCurveDsa::~ElipticCurveDsa() noexcept = default;

pkcs11::enums::Mechanism ElipticCurveDsa::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ECDSA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

