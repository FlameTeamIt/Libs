#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ExtractKeyFromKey.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ExtractKeyFromKey::ExtractKeyFromKey() noexcept = default;
ExtractKeyFromKey::~ExtractKeyFromKey() noexcept = default;

pkcs11::enums::Mechanism ExtractKeyFromKey::getType() const noexcept
{
	return pkcs11::enums::Mechanism::EXTRACT_KEY_FROM_KEY;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

