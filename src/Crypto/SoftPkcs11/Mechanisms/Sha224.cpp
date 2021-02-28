#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Sha224.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Sha224::Sha224() noexcept = default;
Sha224::~Sha224() noexcept = default;

pkcs11::enums::Mechanism Sha224::getType() const noexcept
{
	return pkcs11::enums::Mechanism::SHA224;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

