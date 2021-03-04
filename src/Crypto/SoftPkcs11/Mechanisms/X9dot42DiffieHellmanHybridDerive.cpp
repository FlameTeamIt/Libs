#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/X9dot42DiffieHellmanHybridDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

X9dot42DiffieHellmanHybridDerive::X9dot42DiffieHellmanHybridDerive() noexcept = default;
X9dot42DiffieHellmanHybridDerive::~X9dot42DiffieHellmanHybridDerive() noexcept = default;

pkcs11::enums::Mechanism X9dot42DiffieHellmanHybridDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::X9_42_DH_HYBRID_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

