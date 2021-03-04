#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DsaSha224.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DsaSha224::DsaSha224() noexcept = default;
DsaSha224::~DsaSha224() noexcept = default;

pkcs11::enums::Mechanism DsaSha224::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DSA_SHA224;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

