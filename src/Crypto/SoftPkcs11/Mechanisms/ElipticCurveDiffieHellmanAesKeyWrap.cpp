#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ElipticCurveDiffieHellmanAesKeyWrap.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ElipticCurveDiffieHellmanAesKeyWrap::ElipticCurveDiffieHellmanAesKeyWrap() noexcept = default;
ElipticCurveDiffieHellmanAesKeyWrap::~ElipticCurveDiffieHellmanAesKeyWrap() noexcept = default;

pkcs11::enums::Mechanism ElipticCurveDiffieHellmanAesKeyWrap::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ECDH_AES_KEY_WRAP;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

