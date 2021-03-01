#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCfb8.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesCfb8::AesCfb8() noexcept = default;
AesCfb8::~AesCfb8() noexcept = default;

pkcs11::enums::Mechanism AesCfb8::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_CFB8;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

