#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DiffieHellmanPkcsParameterGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DiffieHellmanPkcsParameterGenerator::DiffieHellmanPkcsParameterGenerator() noexcept = default;
DiffieHellmanPkcsParameterGenerator::~DiffieHellmanPkcsParameterGenerator() noexcept = default;

pkcs11::enums::Mechanism DiffieHellmanPkcsParameterGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DH_PKCS_PARAMETER_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

