#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Cast128Cbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

PbeSha1Cast128Cbc::PbeSha1Cast128Cbc() noexcept = default;
PbeSha1Cast128Cbc::~PbeSha1Cast128Cbc() noexcept = default;

pkcs11::enums::Mechanism PbeSha1Cast128Cbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PBE_SHA1_CAST128_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

