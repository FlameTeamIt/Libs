#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaProbablisticParameterGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DsaProbablisticParameterGenerator::DsaProbablisticParameterGenerator() noexcept = default;
DsaProbablisticParameterGenerator::~DsaProbablisticParameterGenerator() noexcept = default;

pkcs11::enums::Mechanism DsaProbablisticParameterGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DSA_PROBABLISTIC_PARAMETER_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

