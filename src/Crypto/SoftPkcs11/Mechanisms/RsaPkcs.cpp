#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RsaPkcs::RsaPkcs() noexcept = default;
RsaPkcs::~RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_PKCS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

