#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CastCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CastCbc::CastCbc() noexcept = default;
CastCbc::~CastCbc() noexcept = default;

pkcs11::enums::Mechanism CastCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

