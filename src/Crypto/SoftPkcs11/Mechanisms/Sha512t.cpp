#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512t.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512t::Sha512t() noexcept = default;
Sha512t::~Sha512t() noexcept = default;

pkcs11::enums::Mechanism Sha512t::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_T;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

