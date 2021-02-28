#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RipeMd128RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RipeMd128RsaPkcs::RipeMd128RsaPkcs() noexcept = default;
RipeMd128RsaPkcs::~RipeMd128RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism RipeMd128RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RIPEMD128_RSA_PKCS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

