#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/X9dot42DiffieHellmanDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

X9dot42DiffieHellmanDerive::X9dot42DiffieHellmanDerive() noexcept = default;
X9dot42DiffieHellmanDerive::~X9dot42DiffieHellmanDerive() noexcept = default;

pkcs11::enums::Mechanism X9dot42DiffieHellmanDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::X9_42_DH_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

