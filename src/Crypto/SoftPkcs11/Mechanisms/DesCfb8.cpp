#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesCfb8.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DesCfb8::DesCfb8() noexcept = default;
DesCfb8::~DesCfb8() noexcept = default;

pkcs11::enums::Mechanism DesCfb8::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES_CFB8;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

