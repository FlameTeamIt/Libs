#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3Ecb.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Des3Ecb::Des3Ecb() noexcept = default;
Des3Ecb::~Des3Ecb() noexcept = default;

pkcs11::enums::Mechanism Des3Ecb::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES3_ECB;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

