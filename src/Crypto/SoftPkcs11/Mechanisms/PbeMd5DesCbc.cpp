#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeMd5DesCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

PbeMd5DesCbc::PbeMd5DesCbc() noexcept = default;
PbeMd5DesCbc::~PbeMd5DesCbc() noexcept = default;

pkcs11::enums::Mechanism PbeMd5DesCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PBE_MD5_DES_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

