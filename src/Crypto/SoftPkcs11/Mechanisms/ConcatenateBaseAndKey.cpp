#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ConcatenateBaseAndKey.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ConcatenateBaseAndKey::ConcatenateBaseAndKey() noexcept = default;
ConcatenateBaseAndKey::~ConcatenateBaseAndKey() noexcept = default;

pkcs11::enums::Mechanism ConcatenateBaseAndKey::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CONCATENATE_BASE_AND_KEY;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

