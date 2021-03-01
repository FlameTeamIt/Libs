#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CamelliaCtr.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CamelliaCtr::CamelliaCtr() noexcept = default;
CamelliaCtr::~CamelliaCtr() noexcept = default;

pkcs11::enums::Mechanism CamelliaCtr::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CAMELLIA_CTR;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

