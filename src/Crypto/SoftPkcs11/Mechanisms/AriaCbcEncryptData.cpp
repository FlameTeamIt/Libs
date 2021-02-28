#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/AriaCbcEncryptData.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

AriaCbcEncryptData::AriaCbcEncryptData() noexcept = default;
AriaCbcEncryptData::~AriaCbcEncryptData() noexcept = default;

pkcs11::enums::Mechanism AriaCbcEncryptData::getType() const noexcept
{
	return pkcs11::enums::Mechanism::ARIA_CBC_ENCRYPT_DATA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

