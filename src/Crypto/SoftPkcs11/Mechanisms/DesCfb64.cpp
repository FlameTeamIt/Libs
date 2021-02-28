#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesCfb64.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DesCfb64::DesCfb64() noexcept = default;
DesCfb64::~DesCfb64() noexcept = default;

pkcs11::enums::Mechanism DesCfb64::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES_CFB64;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

