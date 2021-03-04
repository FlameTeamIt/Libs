#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaSha256.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DsaSha256::DsaSha256() noexcept = default;
DsaSha256::~DsaSha256() noexcept = default;

pkcs11::enums::Mechanism DsaSha256::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DSA_SHA256;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

