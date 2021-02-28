#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DiffieHellmanPkcsDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DiffieHellmanPkcsDerive::DiffieHellmanPkcsDerive() noexcept = default;
DiffieHellmanPkcsDerive::~DiffieHellmanPkcsDerive() noexcept = default;

pkcs11::enums::Mechanism DiffieHellmanPkcsDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DH_PKCS_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

