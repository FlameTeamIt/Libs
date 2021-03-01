#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaSha384.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DsaSha384::DsaSha384() noexcept = default;
DsaSha384::~DsaSha384() noexcept = default;

pkcs11::enums::Mechanism DsaSha384::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DSA_SHA384;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

