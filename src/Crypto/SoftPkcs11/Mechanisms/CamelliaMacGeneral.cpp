#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaMacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CamelliaMacGeneral::CamelliaMacGeneral() noexcept = default;
CamelliaMacGeneral::~CamelliaMacGeneral() noexcept = default;

pkcs11::enums::Mechanism CamelliaMacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAMELLIA_MAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

