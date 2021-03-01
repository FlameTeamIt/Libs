#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha1.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha1::Sha1() noexcept = default;
Sha1::~Sha1() noexcept = default;

pkcs11::enums::Mechanism Sha1::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA_1;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

