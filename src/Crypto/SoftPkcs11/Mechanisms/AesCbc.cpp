#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesCbc::AesCbc() noexcept = default;
AesCbc::~AesCbc() noexcept = default;

pkcs11::enums::Mechanism AesCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

