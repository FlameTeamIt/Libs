#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Rc2dot40Cbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

PbeSha1Rc2dot40Cbc::PbeSha1Rc2dot40Cbc() noexcept = default;
PbeSha1Rc2dot40Cbc::~PbeSha1Rc2dot40Cbc() noexcept = default;

pkcs11::enums::Mechanism PbeSha1Rc2dot40Cbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PBE_SHA1_RC2_40_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

