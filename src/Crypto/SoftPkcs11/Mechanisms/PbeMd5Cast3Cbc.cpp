#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeMd5Cast3Cbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

PbeMd5Cast3Cbc::PbeMd5Cast3Cbc() noexcept = default;
PbeMd5Cast3Cbc::~PbeMd5Cast3Cbc() noexcept = default;

pkcs11::enums::Mechanism PbeMd5Cast3Cbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PBE_MD5_CAST3_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

