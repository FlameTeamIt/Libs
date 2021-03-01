#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3Cmac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Des3Cmac::Des3Cmac() noexcept = default;
Des3Cmac::~Des3Cmac() noexcept = default;

pkcs11::enums::Mechanism Des3Cmac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES3_CMAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

