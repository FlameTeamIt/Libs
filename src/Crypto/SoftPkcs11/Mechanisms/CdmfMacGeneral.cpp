#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CdmfMacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CdmfMacGeneral::CdmfMacGeneral() noexcept = default;
CdmfMacGeneral::~CdmfMacGeneral() noexcept = default;

pkcs11::enums::Mechanism CdmfMacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CDMF_MAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

