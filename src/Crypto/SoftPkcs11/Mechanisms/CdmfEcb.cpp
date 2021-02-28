#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CdmfEcb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CdmfEcb::CdmfEcb() noexcept = default;
CdmfEcb::~CdmfEcb() noexcept = default;

pkcs11::enums::Mechanism CdmfEcb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CDMF_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

