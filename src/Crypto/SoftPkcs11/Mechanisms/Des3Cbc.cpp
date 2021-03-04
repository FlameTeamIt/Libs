#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Des3Cbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Des3Cbc::Des3Cbc() noexcept = default;
Des3Cbc::~Des3Cbc() noexcept = default;

pkcs11::enums::Mechanism Des3Cbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES3_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

