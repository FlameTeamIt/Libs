#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Fasthash.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Fasthash::Fasthash() noexcept = default;
Fasthash::~Fasthash() noexcept = default;

pkcs11::enums::Mechanism Fasthash::getType() const noexcept
{
	return pkcs11::enums::Mechanism::FASTHASH;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

