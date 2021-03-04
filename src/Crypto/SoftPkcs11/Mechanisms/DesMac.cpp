#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesMac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DesMac::DesMac() noexcept = default;
DesMac::~DesMac() noexcept = default;

pkcs11::enums::Mechanism DesMac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

