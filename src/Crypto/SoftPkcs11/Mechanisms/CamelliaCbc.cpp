#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CamelliaCbc::CamelliaCbc() noexcept = default;
CamelliaCbc::~CamelliaCbc() noexcept = default;

pkcs11::enums::Mechanism CamelliaCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAMELLIA_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

