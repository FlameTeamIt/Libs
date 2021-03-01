#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Des2EdeCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

PbeSha1Des2EdeCbc::PbeSha1Des2EdeCbc() noexcept = default;
PbeSha1Des2EdeCbc::~PbeSha1Des2EdeCbc() noexcept = default;

pkcs11::enums::Mechanism PbeSha1Des2EdeCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PBE_SHA1_DES2_EDE_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

