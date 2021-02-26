#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Cast5Cbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

PbeSha1Cast5Cbc::PbeSha1Cast5Cbc() noexcept = default;

PbeSha1Cast5Cbc::~PbeSha1Cast5Cbc() noexcept = default;

pkcs11::enums::Mechanism
PbeSha1Cast5Cbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PBE_SHA1_CAST5_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

