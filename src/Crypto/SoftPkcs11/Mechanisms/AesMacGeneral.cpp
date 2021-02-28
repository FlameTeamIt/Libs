#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AesMacGeneral.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AesMacGeneral::AesMacGeneral() noexcept = default;
AesMacGeneral::~AesMacGeneral() noexcept = default;

pkcs11::enums::Mechanism AesMacGeneral::getType() const noexcept
{
	return pkcs11::enums::Mechanism::AES_MAC_GENERAL;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

