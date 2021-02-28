#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeMd5CastCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

PbeMd5CastCbc::PbeMd5CastCbc() noexcept = default;

PbeMd5CastCbc::~PbeMd5CastCbc() noexcept = default;

pkcs11::enums::Mechanism PbeMd5CastCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PBE_MD5_CAST_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

