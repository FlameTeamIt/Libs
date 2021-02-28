#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaShaweTaylorParameterGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DsaShaweTaylorParameterGenerator::DsaShaweTaylorParameterGenerator() noexcept = default;
DsaShaweTaylorParameterGenerator::~DsaShaweTaylorParameterGenerator() noexcept = default;

pkcs11::enums::Mechanism DsaShaweTaylorParameterGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DSA_SHAWE_TAYLOR_PARAMETER_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

