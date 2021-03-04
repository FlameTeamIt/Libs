#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCfb128.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesCfb128::AesCfb128() noexcept = default;
AesCfb128::~AesCfb128() noexcept = default;

pkcs11::enums::Mechanism AesCfb128::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_CFB128;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

