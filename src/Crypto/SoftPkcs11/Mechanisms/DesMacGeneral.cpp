#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesMacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DesMacGeneral::DesMacGeneral() noexcept = default;
DesMacGeneral::~DesMacGeneral() noexcept = default;

pkcs11::enums::Mechanism DesMacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES_MAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

