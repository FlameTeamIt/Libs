#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesMac.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesMac::AesMac() noexcept = default;
AesMac::~AesMac() noexcept = default;

pkcs11::enums::Mechanism AesMac::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_MAC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

