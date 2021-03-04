#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3Mac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Des3Mac::Des3Mac() noexcept = default;
Des3Mac::~Des3Mac() noexcept = default;

pkcs11::enums::Mechanism Des3Mac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES3_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

