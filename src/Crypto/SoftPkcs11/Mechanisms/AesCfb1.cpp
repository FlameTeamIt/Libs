#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCfb1.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesCfb1::AesCfb1() noexcept = default;
AesCfb1::~AesCfb1() noexcept = default;

pkcs11::enums::Mechanism AesCfb1::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_CFB1;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

