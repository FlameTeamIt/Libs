#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CdmfCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CdmfCbc::CdmfCbc() noexcept = default;
CdmfCbc::~CdmfCbc() noexcept = default;

pkcs11::enums::Mechanism CdmfCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CDMF_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

