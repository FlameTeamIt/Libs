#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd160RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RipeMd160RsaPkcs::RipeMd160RsaPkcs() noexcept = default;
RipeMd160RsaPkcs::~RipeMd160RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism RipeMd160RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RIPEMD160_RSA_PKCS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

