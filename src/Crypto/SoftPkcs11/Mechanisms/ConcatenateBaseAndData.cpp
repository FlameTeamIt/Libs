#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/ConcatenateBaseAndData.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

ConcatenateBaseAndData::ConcatenateBaseAndData() noexcept = default;
ConcatenateBaseAndData::~ConcatenateBaseAndData() noexcept = default;

pkcs11::enums::Mechanism ConcatenateBaseAndData::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CONCATENATE_BASE_AND_DATA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

