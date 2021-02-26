#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDH1Derive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ElipticCurveDH1Derive::ElipticCurveDH1Derive() noexcept = default;

ElipticCurveDH1Derive::~ElipticCurveDH1Derive() noexcept = default;

pkcs11::enums::Mechanism
ElipticCurveDH1Derive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ECDH1_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

