#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaParameterGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DsaParameterGenerator::DsaParameterGenerator() noexcept = default;
DsaParameterGenerator::~DsaParameterGenerator() noexcept = default;

pkcs11::enums::Mechanism DsaParameterGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DSA_PARAMETER_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

