#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CastMac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CastMac::CastMac() noexcept = default;
CastMac::~CastMac() noexcept = default;

pkcs11::enums::Mechanism CastMac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

