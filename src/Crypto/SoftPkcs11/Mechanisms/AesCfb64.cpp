#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCfb64.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesCfb64::AesCfb64() noexcept = default;
AesCfb64::~AesCfb64() noexcept = default;

pkcs11::enums::Mechanism AesCfb64::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_CFB64;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

