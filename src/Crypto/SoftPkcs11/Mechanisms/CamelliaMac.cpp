#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaMac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CamelliaMac::CamelliaMac() noexcept = default;
CamelliaMac::~CamelliaMac() noexcept = default;

pkcs11::enums::Mechanism CamelliaMac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAMELLIA_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

