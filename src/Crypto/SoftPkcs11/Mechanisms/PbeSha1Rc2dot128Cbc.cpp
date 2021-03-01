#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Rc2dot128Cbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

PbeSha1Rc2dot128Cbc::PbeSha1Rc2dot128Cbc() noexcept = default;
PbeSha1Rc2dot128Cbc::~PbeSha1Rc2dot128Cbc() noexcept = default;

pkcs11::enums::Mechanism PbeSha1Rc2dot128Cbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PBE_SHA1_RC2_128_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

