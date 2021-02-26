#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeMd5Cast5Cbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

PbeMd5Cast5Cbc::PbeMd5Cast5Cbc() noexcept = default;

PbeMd5Cast5Cbc::~PbeMd5Cast5Cbc() noexcept = default;

pkcs11::enums::Mechanism
PbeMd5Cast5Cbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PBE_MD5_CAST5_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

