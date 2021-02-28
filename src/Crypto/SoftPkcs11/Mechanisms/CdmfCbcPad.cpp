#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CdmfCbcPad.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CdmfCbcPad::CdmfCbcPad() noexcept = default;
CdmfCbcPad::~CdmfCbcPad() noexcept = default;

pkcs11::enums::Mechanism CdmfCbcPad::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CDMF_CBC_PAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

