#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaSha1.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DsaSha1::DsaSha1() noexcept = default;
DsaSha1::~DsaSha1() noexcept = default;

pkcs11::enums::Mechanism DsaSha1::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DSA_SHA1;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

