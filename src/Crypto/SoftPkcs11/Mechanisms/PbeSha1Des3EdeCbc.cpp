#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Des3EdeCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

PbeSha1Des3EdeCbc::PbeSha1Des3EdeCbc() noexcept = default;
PbeSha1Des3EdeCbc::~PbeSha1Des3EdeCbc() noexcept = default;

pkcs11::enums::Mechanism PbeSha1Des3EdeCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PBE_SHA1_DES3_EDE_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

