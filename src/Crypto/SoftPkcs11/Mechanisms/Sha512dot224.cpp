#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha512dot224.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha512dot224::Sha512dot224() noexcept = default;
Sha512dot224::~Sha512dot224() noexcept = default;

pkcs11::enums::Mechanism Sha512dot224::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA512_224;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

