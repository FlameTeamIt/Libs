#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/RsaX9dot31.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RsaX9dot31::RsaX9dot31() noexcept = default;
RsaX9dot31::~RsaX9dot31() noexcept = default;

pkcs11::enums::Mechanism RsaX9dot31::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_X9_31;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

