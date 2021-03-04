#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/X9dot42DiffieHellmanParameterGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

X9dot42DiffieHellmanParameterGenerator::X9dot42DiffieHellmanParameterGenerator() noexcept = default;
X9dot42DiffieHellmanParameterGenerator::~X9dot42DiffieHellmanParameterGenerator() noexcept = default;

pkcs11::enums::Mechanism X9dot42DiffieHellmanParameterGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::X9_42_DH_PARAMETER_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

