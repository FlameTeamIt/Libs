#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeMd5Cast128Cbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

PbeMd5Cast128Cbc::PbeMd5Cast128Cbc() noexcept = default;
PbeMd5Cast128Cbc::~PbeMd5Cast128Cbc() noexcept = default;

pkcs11::enums::Mechanism PbeMd5Cast128Cbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PBE_MD5_CAST128_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

