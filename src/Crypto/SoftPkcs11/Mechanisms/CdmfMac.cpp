#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CdmfMac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CdmfMac::CdmfMac() noexcept = default;
CdmfMac::~CdmfMac() noexcept = default;

pkcs11::enums::Mechanism CdmfMac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CDMF_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

