#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CdmfKeyGenerator.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CdmfKeyGenerator::CdmfKeyGenerator() noexcept = default;
CdmfKeyGenerator::~CdmfKeyGenerator() noexcept = default;

pkcs11::enums::Mechanism CdmfKeyGenerator::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CDMF_KEY_GEN;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

