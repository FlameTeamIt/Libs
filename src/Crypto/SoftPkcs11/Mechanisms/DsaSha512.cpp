#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaSha512.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DsaSha512::DsaSha512() noexcept = default;
DsaSha512::~DsaSha512() noexcept = default;

pkcs11::enums::Mechanism DsaSha512::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DSA_SHA512;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

