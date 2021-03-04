#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CastEcb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CastEcb::CastEcb() noexcept = default;
CastEcb::~CastEcb() noexcept = default;

pkcs11::enums::Mechanism CastEcb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

