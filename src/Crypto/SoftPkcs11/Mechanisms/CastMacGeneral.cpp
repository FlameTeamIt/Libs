#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CastMacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CastMacGeneral::CastMacGeneral() noexcept = default;
CastMacGeneral::~CastMacGeneral() noexcept = default;

pkcs11::enums::Mechanism CastMacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAST_MAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

